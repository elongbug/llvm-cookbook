#include "llvm/ADT/SmallPtrSet.h"
#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/Analysis/AssumptionCache.h"
#include "llvm/Analysis/CallGraph.h"
#include "llvm/Analysis/InlineCost.h"
#include "llvm/IR/CallSite.h"
#include "llvm/IR/CallingConv.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/Transforms/IPO.h"
#include "llvm/Transforms/IPO/InlinerPass.h"

using namespace llvm;
namespace {

class MyInliner : public Inliner {
  InlineCostAnalysis *ICA;

public:
  MyInliner()
      : Inliner(ID, -2000000000,
                /*InsertLifetime*/ true),
        ICA(nullptr) {
    initializeMyInlinerPass(*PassRegistry::getPassRegistry());
  }

  MyInliner(bool InsertLifetime)
      : Inliner(ID, -2000000000, InsertLifetime), ICA(nullptr) {
    initializeMyInlinerPass(*PassRegistry::getPassRegistry());
  }

  static char ID;

  InlineCost getInlineCost(CallSite CS) override;

  void getAnalysisUsage(AnalysisUsage &AU) const override;
  bool runOnSCC(CallGraphSCC &SCC) override;

  using llvm::Pass::doFinalization;
  bool doFinalization(CallGraph &CG) override {
    return removeDeadFunctions(CG, /*AlwaysInlineOnly=*/
                               true);
  }
};
} // namespace

char MyInliner::ID = 0;
INITIALIZE_PASS_BEGIN(MyInliner, "my-inline", "Inliner for my_inline functions",
                      false, false)
INITIALIZE_AG_DEPENDENCY(AliasAnalysis)
INITIALIZE_PASS_DEPENDENCY(AssumptionCacheTracker)
INITIALIZE_PASS_DEPENDENCY(CallGraphWrapperPass)
INITIALIZE_PASS_DEPENDENCY(InlineCostAnalysis)
INITIALIZE_PASS_END(MyInliner, "my-inline",
                    "Inliner for always_inline functions", false, false)

Pass *llvm::createMyInlinerPass() { return new MyInliner(); }

Pass *llvm::createMyInlinerPass(bool InsertLifetime) {
  return new MyInliner(InsertLifetime);
}

InlineCost MyInliner::getInlineCost(CallSite CS) {
  Function *Callee = CS.getCalledFunction();
  if (Callee && !Callee->isDeclaration() &&
      CS.hasFnAttr(Attribute::AlwaysInline) && ICA->isInlineViable(*Callee))
    return InlineCost::getAlways();

  return InlineCost::getNever();
}

bool MyInliner::runOnSCC(CallGraphSCC &SCC) {
  ICA = &getAnalysis<InlineCostAnalysis>();
  return Inliner::runOnSCC(SCC);
}

void MyInliner::getAnalysisUsage(AnalysisUsage &AU) const {
  AU.addRequired<InlineCostAnalysis>();
  Inliner::getAnalysisUsage(AU);
}
