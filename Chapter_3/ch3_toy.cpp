#include "llvm/ADT/STLExtras.h"
#include "llvm/Analysis/Passes.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/MCJIT.h"
#include "llvm/ExecutionEngine/SectionMemoryManager.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Transforms/Scalar.h"
#include <cctype>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
using namespace llvm;

enum Token {
  EOF_TOKEN = -1,

  DEF_TOKEN = -2,

  IDENTIFIER_TOKEN = -3,
  NUMERIC_TOKEN = -4,

  IF_TOKEN = -5,
  THEN_TOKEN = -6,
  ELSE_TOKEN = -7,
  FOR_TOKEN = -8,
  IN_TOKEN = -9,

  BINARY_TOKEN = -10,
  UNARY_TOKEN = -11
};

FILE *file;
static std::string Identifier_string;
static int Numeric_Val;

static int get_token() {
  static int LastChar = ' ';

  while (isspace(LastChar))
    LastChar = fgetc(file);

  if (isalpha(LastChar)) {
    Identifier_string = LastChar;
    while (isalnum((LastChar = fgetc(file))))
      Identifier_string += LastChar;

    if (Identifier_string == "def")
      return DEF_TOKEN;
    if (Identifier_string == "if")
      return IF_TOKEN;
    if (Identifier_string == "then")
      return THEN_TOKEN;
    if (Identifier_string == "else")
      return ELSE_TOKEN;
    if (Identifier_string == "for")
      return FOR_TOKEN;
    if (Identifier_string == "in")
      return IN_TOKEN;
    if (Identifier_string == "binary")
      return BINARY_TOKEN;
    if (Identifier_string == "unary")
      return UNARY_TOKEN;
    return IDENTIFIER_TOKEN;
  }

  if (isdigit(LastChar) || LastChar == '.') {
    std::string NumStr;
    do {
      NumStr += LastChar;
      LastChar = fgetc(file);
    } while (isdigit(LastChar) || LastChar == '.');

    Numeric_Val = std::stoi(NumStr.c_str(), 0);
    return NUMERIC_TOKEN;
  }

  if (LastChar == '#') {
    do
      LastChar = fgetc(file);
    while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');

    if (LastChar != EOF)
      return get_token();
  }

  if (LastChar == EOF)
    return EOF_TOKEN;

  int ThisChar = LastChar;
  LastChar = fgetc(file);
  return ThisChar;
}

namespace {
class BaseAST {
public:
  virtual ~BaseAST() {}
  virtual Value *Codegen() = 0;
};

class NumericAST : public BaseAST {
  int numeric_val;

public:
  NumericAST(int val) : numeric_val(val) {}
  Value *Codegen() override;
};

class VariableAST : public BaseAST {
  std::string Var_Name;

public:
  VariableAST(const std::string &name) : Var_Name(name) {}
  Value *Codegen() override;
};

class ExprUnaryAST : public BaseAST {
  char Opcode;
  BaseAST *Operand;

public:
  ExprUnaryAST(char opcode, BaseAST *operand)
      : Opcode(opcode), Operand(operand) {}
  Value *Codegen() override;
};

class BinaryAST : public BaseAST {
  std::string Bin_Operator;
  BaseAST *LHS, *RHS;

public:
  BinaryAST(std::string op, BaseAST *lhs, BaseAST *rhs)
      : Bin_Operator(op), LHS(lhs), RHS(rhs) {}
  Value *Codegen() override;
};

class FunctionCallAST : public BaseAST {
  std::string Function_Callee;
  std::vector<BaseAST *> Function_Arguments;

public:
  FunctionCallAST(const std::string &callee, std::vector<BaseAST *> &args)
      : Function_Callee(callee), Function_Arguments(args) {}
  Value *Codegen() override;
};

class ExprIfAST : public BaseAST {
  BaseAST *Cond, *Then, *Else;

public:
  ExprIfAST(BaseAST *cond, BaseAST *then, BaseAST *else_st)
      : Cond(cond), Then(then), Else(else_st) {}
  Value *Codegen() override;
};

class ExprForAST : public BaseAST {
  std::string Var_Name;
  BaseAST *Start, *End, *Step, *Body;

public:
  ExprForAST(const std::string &varname, BaseAST *start, BaseAST *end,
             BaseAST *step, BaseAST *body)
      : Var_Name(varname), Start(start), End(end), Step(step), Body(body) {}
  Value *Codegen() override;
};

class FunctionDeclAST {
  std::string Func_Name;
  std::vector<std::string> Arguments;
  bool isOperator;
  unsigned Precedence;

public:
  FunctionDeclAST(const std::string &name, const std::vector<std::string> &args,
                  bool isoperator = false, unsigned prec = 0)
      : Func_Name(name), Arguments(args), isOperator(isoperator),
        Precedence(prec) {}

  bool isUnaryOp() const { return isOperator && Arguments.size() == 1; }
  bool isBinaryOp() const { return isOperator && Arguments.size() == 2; }

  char getOperatorName() const {
    assert(isUnaryOp() || isBinaryOp());
    return Func_Name[Func_Name.size() - 1];
  }

  unsigned getBinaryPrecedence() const { return Precedence; }

  Function *Codegen();
};

class FunctionDefnAST {
  FunctionDeclAST *Func_Decl;
  BaseAST *Body;

public:
  FunctionDefnAST(FunctionDeclAST *proto, BaseAST *body)
      : Func_Decl(proto), Body(body) {}

  Function *Codegen();
};
} // namespace

static int Current_token;
static int next_token() { return Current_token = get_token(); }

static std::map<char, int> Operator_Precedence;

static int getBinOpPrecedence() {
  if (!isascii(Current_token))
    return -1;

  int Operator_Prec = Operator_Precedence[Current_token];
  if (Operator_Prec <= 0)
    return -1;
  return Operator_Prec;
}

static BaseAST *expression_parser();

static BaseAST *identifier_parser() {
  std::string IdName = Identifier_string;

  next_token();

  if (Current_token != '(')
    return new VariableAST(IdName);

  next_token();
  std::vector<BaseAST *> Arguments;
  if (Current_token != ')') {
    while (1) {
      BaseAST *Arg = expression_parser();
      if (!Arg)
        return 0;
      Arguments.push_back(Arg);

      if (Current_token == ')')
        break;

      if (Current_token != ',')
        return 0;
      next_token();
    }
  }

  next_token();

  return new FunctionCallAST(IdName, Arguments);
}

static BaseAST *numeric_parser() {
  BaseAST *Result = new NumericAST(Numeric_Val);
  next_token();
  return Result;
}

static BaseAST *paran_parser() {
  next_token();
  BaseAST *V = expression_parser();
  if (!V)
    return 0;

  if (Current_token != ')')
    return 0;
  next_token();
  return V;
}

static BaseAST *If_parser() {
  next_token();

  BaseAST *Cond = expression_parser();
  if (!Cond)
    return 0;

  if (Current_token != THEN_TOKEN)
    return 0;
  next_token();

  BaseAST *Then = expression_parser();
  if (Then == 0)
    return 0;

  if (Current_token != ELSE_TOKEN)
    return 0;

  next_token();

  BaseAST *Else = expression_parser();
  if (!Else)
    return 0;

  return new ExprIfAST(Cond, Then, Else);
}

static BaseAST *For_parser() {
  next_token();

  if (Current_token != IDENTIFIER_TOKEN)
    return 0;

  std::string IdName = Identifier_string;
  next_token();

  if (Current_token != '=')
    return 0;
  next_token();

  BaseAST *Start = expression_parser();
  if (Start == 0)
    return 0;
  if (Current_token != ',')
    return 0;
  next_token();

  BaseAST *End = expression_parser();
  if (End == 0)
    return 0;

  BaseAST *Step = 0;
  if (Current_token == ',') {
    next_token();
    Step = expression_parser();
    if (Step == 0)
      return 0;
  }

  if (Current_token != IN_TOKEN)
    return 0;
  next_token();

  BaseAST *Body = expression_parser();
  if (Body == 0)
    return 0;

  return new ExprForAST(IdName, Start, End, Step, Body);
}

static BaseAST *Base_Parser() {
  switch (Current_token) {
  default:
    return 0;
  case IDENTIFIER_TOKEN:
    return identifier_parser();
  case NUMERIC_TOKEN:
    return numeric_parser();
  case '(':
    return paran_parser();
  case IF_TOKEN:
    return If_parser();
  case FOR_TOKEN:
    return For_parser();
  }
}

static BaseAST *unary_parser() {
  if (!isascii(Current_token) || Current_token == '(' || Current_token == ',')
    return Base_Parser();

  int Op = Current_token;
  next_token();
  if (BaseAST *Operand = unary_parser())
    return new ExprUnaryAST(Op, Operand);
  return 0;
}

static BaseAST *binary_op_parser(int Old_Prec, BaseAST *LHS) {
  while (1) {
    int Operator_Prec = getBinOpPrecedence();

    if (Operator_Prec < Old_Prec)
      return LHS;

    int BinOp = Current_token;
    next_token();

    BaseAST *RHS = unary_parser();
    if (!RHS)
      return 0;

    int NextPrec = getBinOpPrecedence();
    if (Operator_Prec < NextPrec) {
      RHS = binary_op_parser(Operator_Prec + 1, RHS);
      if (RHS == 0)
        return 0;
    }

    LHS = new BinaryAST(std::to_string(BinOp), LHS, RHS);
  }
}

static BaseAST *expression_parser() {
  BaseAST *LHS = unary_parser();
  if (!LHS)
    return 0;

  return binary_op_parser(0, LHS);
}

static FunctionDeclAST *func_decl_parser() {
  std::string FnName;

  unsigned Kind = 0;
  unsigned BinaryPrecedence = 30;

  switch (Current_token) {
  default:
    return 0;
  case IDENTIFIER_TOKEN:
    FnName = Identifier_string;
    Kind = 0;
    next_token();
    break;
  case UNARY_TOKEN:
    next_token();
    if (!isascii(Current_token))
      return 0;
    FnName = "unary";
    FnName += (char)Current_token;
    Kind = 1;
    next_token();
    break;
  case BINARY_TOKEN:
    next_token();
    if (!isascii(Current_token))
      return 0;
    FnName = "binary";
    FnName += (char)Current_token;
    Kind = 2;
    next_token();

    if (Current_token == NUMERIC_TOKEN) {
      if (Numeric_Val < 1 || Numeric_Val > 100)
        return 0;
      BinaryPrecedence = (unsigned)Numeric_Val;
      next_token();
    }
    break;
  }

  if (Current_token != '(')
    return 0;

  std::vector<std::string> ArgNames;
  while (next_token() == IDENTIFIER_TOKEN)
    ArgNames.push_back(Identifier_string);
  if (Current_token != ')')
    return 0;

  next_token();

  if (Kind && ArgNames.size() != Kind)
    return 0;

  return new FunctionDeclAST(FnName, ArgNames, Kind != 0, BinaryPrecedence);
}

static FunctionDefnAST *func_defn_parser() {
  next_token();
  FunctionDeclAST *Func_Decl = func_decl_parser();
  if (Func_Decl == 0)
    return 0;

  if (BaseAST *E = expression_parser())
    return new FunctionDefnAST(Func_Decl, E);
  return 0;
}

static FunctionDefnAST *top_level_parser() {
  if (BaseAST *E = expression_parser()) {
    FunctionDeclAST *Func_Decl =
        new FunctionDeclAST("", std::vector<std::string>());
    return new FunctionDefnAST(Func_Decl, E);
  }
  return 0;
}

static Module *Module_Ob;
static LLVMContext MyGlobalContext;
static IRBuilder<> Builder(MyGlobalContext);
static std::map<std::string, Value *> Named_Values;
static legacy::FunctionPassManager *Global_FP;

Value *NumericAST::Codegen() {
  return ConstantInt::get(Type::getInt32Ty(MyGlobalContext), numeric_val);
}

Value *VariableAST::Codegen() {
  Value *V = Named_Values[Var_Name];
  return V ? V : 0;
}

Value *ExprUnaryAST::Codegen() {
  Value *OperandV = Operand->Codegen();
  if (OperandV == 0)
    return 0;

  Function *F = Module_Ob->getFunction(std::string("unary") + Opcode);
  if (F == 0)
    return 0;

  return Builder.CreateCall(F, OperandV, "unop");
}

Value *BinaryAST::Codegen() {
  Value *L = LHS->Codegen();
  Value *R = RHS->Codegen();
  if (L == 0 || R == 0)
    return 0;

  switch (std::stoi(Bin_Operator)) {
  case '+':
    return Builder.CreateAdd(L, R, "addtmp");
  case '-':
    return Builder.CreateSub(L, R, "subtmp");
  case '*':
    return Builder.CreateMul(L, R, "multmp");
  case '<':
    L = Builder.CreateICmpULT(L, R, "cmptmp");
    return Builder.CreateZExt(L, Type::getInt32Ty(MyGlobalContext),
                              "booltmp");
  default:
    break;
  }

  Function *F = Module_Ob->getFunction(std::string("binary") + Bin_Operator);
  assert(F && "binary operator not found!");

  Value *Ops[] = {L, R};
  return Builder.CreateCall(F, Ops, "binop");
}

Value *FunctionCallAST::Codegen() {
  Function *CalleeF = Module_Ob->getFunction(Function_Callee);
  if (CalleeF == 0)
    return 0;

  if (CalleeF->arg_size() != Function_Arguments.size())
    return 0;

  std::vector<Value *> ArgsV;
  for (unsigned i = 0, e = Function_Arguments.size(); i != e; ++i) {
    ArgsV.push_back(Function_Arguments[i]->Codegen());
    if (ArgsV.back() == 0)
      return 0;
  }

  return Builder.CreateCall(CalleeF, ArgsV, "calltmp");
}

Value *ExprIfAST::Codegen() {
  Value *CondV = Cond->Codegen();
  if (CondV == 0)
    return 0;

  CondV = Builder.CreateICmpNE(
      CondV, ConstantInt::get(Type::getInt32Ty(MyGlobalContext), 0),
      "ifcond");

  Function *TheFunction = Builder.GetInsertBlock()->getParent();

  BasicBlock *ThenBB =
      BasicBlock::Create(MyGlobalContext, "then", TheFunction);
  BasicBlock *ElseBB = BasicBlock::Create(MyGlobalContext, "else");
  BasicBlock *MergeBB = BasicBlock::Create(MyGlobalContext, "ifcont");

  Builder.CreateCondBr(CondV, ThenBB, ElseBB);

  Builder.SetInsertPoint(ThenBB);

  Value *ThenV = Then->Codegen();
  if (ThenV == 0)
    return 0;

  Builder.CreateBr(MergeBB);
  ThenBB = Builder.GetInsertBlock();

  TheFunction->getBasicBlockList().push_back(ElseBB);
  Builder.SetInsertPoint(ElseBB);

  Value *ElseV = Else->Codegen();
  if (ElseV == 0)
    return 0;

  Builder.CreateBr(MergeBB);
  ElseBB = Builder.GetInsertBlock();

  TheFunction->getBasicBlockList().push_back(MergeBB);
  Builder.SetInsertPoint(MergeBB);
  PHINode *PN =
      Builder.CreatePHI(Type::getInt32Ty(MyGlobalContext), 2, "iftmp");

  PN->addIncoming(ThenV, ThenBB);
  PN->addIncoming(ElseV, ElseBB);
  return PN;
}

Value *ExprForAST::Codegen() {

  Value *StartVal = Start->Codegen();
  if (StartVal == 0)
    return 0;

  Function *TheFunction = Builder.GetInsertBlock()->getParent();
  BasicBlock *PreheaderBB = Builder.GetInsertBlock();
  BasicBlock *LoopBB =
      BasicBlock::Create(MyGlobalContext, "loop", TheFunction);

  Builder.CreateBr(LoopBB);

  Builder.SetInsertPoint(LoopBB);

  PHINode *Variable = Builder.CreatePHI(Type::getInt32Ty(MyGlobalContext), 2,
                                        Var_Name.c_str());
  Variable->addIncoming(StartVal, PreheaderBB);

  Value *OldVal = Named_Values[Var_Name];
  Named_Values[Var_Name] = Variable;

  if (Body->Codegen() == 0)
    return 0;

  Value *StepVal;
  if (Step) {
    StepVal = Step->Codegen();
    if (StepVal == 0)
      return 0;
  } else {

    StepVal = ConstantInt::get(Type::getInt32Ty(MyGlobalContext), 1);
  }

  Value *NextVar = Builder.CreateAdd(Variable, StepVal, "nextvar");

  Value *EndCond = End->Codegen();
  if (EndCond == 0)
    return EndCond;

  EndCond = Builder.CreateICmpNE(
      EndCond, ConstantInt::get(Type::getInt32Ty(MyGlobalContext), 0),
      "loopcond");

  BasicBlock *LoopEndBB = Builder.GetInsertBlock();
  BasicBlock *AfterBB =
      BasicBlock::Create(MyGlobalContext, "afterloop", TheFunction);

  Builder.CreateCondBr(EndCond, LoopBB, AfterBB);

  Builder.SetInsertPoint(AfterBB);

  Variable->addIncoming(NextVar, LoopEndBB);

  if (OldVal)
    Named_Values[Var_Name] = OldVal;
  else
    Named_Values.erase(Var_Name);

  return Constant::getNullValue(Type::getInt32Ty(MyGlobalContext));
}

Function *FunctionDeclAST::Codegen() {
  std::vector<Type *> Integers(Arguments.size(),
                               Type::getInt32Ty(MyGlobalContext));
  FunctionType *FT =
      FunctionType::get(Type::getInt32Ty(MyGlobalContext), Integers, false);

  Function *F =
      Function::Create(FT, Function::ExternalLinkage, Func_Name, Module_Ob);

  if (F->getName() != Func_Name) {
    F->eraseFromParent();
    F = Module_Ob->getFunction(Func_Name);

    if (!F->empty()) {
      return 0;
    }

    if (F->arg_size() != Arguments.size()) {
      return 0;
    }
  }

  unsigned Idx = 0;
  for (Function::arg_iterator AI = F->arg_begin(); Idx != Arguments.size();
       ++AI, ++Idx) {
    AI->setName(Arguments[Idx]);

    Named_Values[Arguments[Idx]] = AI;
  }

  return F;
}

Function *FunctionDefnAST::Codegen() {
  Named_Values.clear();

  Function *TheFunction = Func_Decl->Codegen();
  if (TheFunction == 0)
    return 0;

  if (Func_Decl->isBinaryOp())
    Operator_Precedence[Func_Decl->getOperatorName()] =
        Func_Decl->getBinaryPrecedence();

  BasicBlock *BB = BasicBlock::Create(MyGlobalContext, "entry", TheFunction);
  Builder.SetInsertPoint(BB);

  if (Value *RetVal = Body->Codegen()) {
    Builder.CreateRet(RetVal);

    verifyFunction(*TheFunction);

    Global_FP->run(*TheFunction);

    return TheFunction;
  }

  TheFunction->eraseFromParent();

  if (Func_Decl->isBinaryOp())
    Operator_Precedence.erase(Func_Decl->getOperatorName());
  return 0;
}

static ExecutionEngine *TheExecutionEngine;

static void HandleDefinition() {
  if (FunctionDefnAST *F = func_defn_parser()) {
    if (Function *LF = F->Codegen()) {
    }
  } else {
    next_token();
  }
}

static void HandleTopLevelExpression() {
  if (FunctionDefnAST *F = top_level_parser()) {
    if (Function *LF = F->Codegen()) {
      TheExecutionEngine->finalizeObject();
      void *FPtr = TheExecutionEngine->getPointerToFunction(LF);

      double (*FP)() = (double (*)())(intptr_t)FPtr;
      fprintf(stderr, "Evaluated to %f\n", FP());
    }
  } else {
    next_token();
  }
}

static void Driver() {
  while (1) {
    switch (Current_token) {
    case EOF_TOKEN:
      return;
    case ';':
      next_token();
      break;
    case DEF_TOKEN:
      HandleDefinition();
      break;
    default:
      HandleTopLevelExpression();
      break;
    }
  }
}

extern "C" double putchard(double X) {
  putchar((char)X);
  return 0;
}

extern "C" double printd(double X) {
  printf("%f\n", X);
  return 0;
}

static void init_precedence() {
  Operator_Precedence['<'] = 10;
  Operator_Precedence['-'] = 20;
  Operator_Precedence['+'] = 30;
  Operator_Precedence['/'] = 40;
  Operator_Precedence['*'] = 50;
}

int main(int argc, char *argv[]) {
  InitializeNativeTarget();
  InitializeNativeTargetAsmPrinter();
  InitializeNativeTargetAsmParser();
  LLVMContext &Context = MyGlobalContext;

  init_precedence();

  file = fopen(argv[1], "r");
  if (file == 0) {
    printf("Could not open file\n");
  }
  next_token();

  std::unique_ptr<Module> Owner = make_unique<Module>("my compiler", Context);
  Module_Ob = Owner.get();

  std::string ErrStr;
  TheExecutionEngine =
      EngineBuilder(std::move(Owner))
          .setErrorStr(&ErrStr)
          .setMCJITMemoryManager(llvm::make_unique<SectionMemoryManager>())
          .create();
  if (!TheExecutionEngine) {
    exit(1);
  }

  legacy::FunctionPassManager OurFPM(Module_Ob);

  Module_Ob->setDataLayout(*TheExecutionEngine->getDataLayout());
  OurFPM.add(createBasicAliasAnalysisPass());
  OurFPM.add(createInstructionCombiningPass());
  OurFPM.add(createReassociatePass());
  OurFPM.add(createGVNPass());
  OurFPM.add(createCFGSimplificationPass());

  OurFPM.doInitialization();

  Global_FP = &OurFPM;

  Driver();

  Global_FP = 0;

  Module_Ob->print(llvm::outs(),nullptr);

  return 0;
}
