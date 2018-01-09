/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*DAG Instruction Selector for the TOY target                                 *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

// *** NOTE: This file is #included into the middle of the target
// *** instruction selector class.  These functions are really methods.

// The main instruction selector code.
SDNode *SelectCode(SDNode *N) {
  // Some target values are emitted as 2 bytes, TARGET_VAL handles
  // this.
  #define TARGET_VAL(X) X & 255, unsigned(X) >> 8
  static const unsigned char MatcherTable[] = {
/*0*/       OPC_SwitchOpcode /*12 cases */, 22, TARGET_VAL(ISD::LOAD),// ->26
/*4*/         OPC_RecordMemRef,
/*5*/         OPC_RecordNode, // #0 = 'ld' chained node
/*6*/         OPC_RecordChild1, // #1 = $addr
/*7*/         OPC_CheckPredicate, 0, // Predicate_unindexedload
/*9*/         OPC_CheckPredicate, 1, // Predicate_load
/*11*/        OPC_CheckType, MVT::i32,
/*13*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*16*/        OPC_EmitMergeInputChains1_0,
/*17*/        OPC_MorphNodeTo, TARGET_VAL(TOY::LDR), 0|OPFL_Chain|OPFL_MemRefs,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
              // Src: (ld:i32 addr:iPTR:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
              // Dst: (LDR:i32 addr:i32:$addr)
/*26*/      /*SwitchOpcode*/ 23, TARGET_VAL(ISD::STORE),// ->52
/*29*/        OPC_RecordMemRef,
/*30*/        OPC_RecordNode, // #0 = 'st' chained node
/*31*/        OPC_RecordChild1, // #1 = $val
/*32*/        OPC_CheckChild1Type, MVT::i32,
/*34*/        OPC_RecordChild2, // #2 = $addr
/*35*/        OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*37*/        OPC_CheckPredicate, 3, // Predicate_store
/*39*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*42*/        OPC_EmitMergeInputChains1_0,
/*43*/        OPC_MorphNodeTo, TARGET_VAL(TOY::STR), 0|OPFL_Chain|OPFL_MemRefs,
                  0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
              // Src: (st i32:i32:$val, addr:iPTR:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
              // Dst: (STR i32:i32:$val, addr:i32:$addr)
/*52*/      /*SwitchOpcode*/ 26, TARGET_VAL(ISD::CALLSEQ_END),// ->81
/*55*/        OPC_RecordNode, // #0 = 'callseq_end' chained node
/*56*/        OPC_CaptureGlueInput,
/*57*/        OPC_RecordChild1, // #1 = $amt1
/*58*/        OPC_MoveChild, 1,
/*60*/        OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*63*/        OPC_MoveParent,
/*64*/        OPC_RecordChild2, // #2 = $amt2
/*65*/        OPC_MoveChild, 2,
/*67*/        OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*70*/        OPC_MoveParent,
/*71*/        OPC_EmitMergeInputChains1_0,
/*72*/        OPC_MorphNodeTo, TARGET_VAL(TOY::ADJCALLSTACKUP), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (callseq_end (timm:i32):$amt1, (timm:i32):$amt2) - Complexity = 9
              // Dst: (ADJCALLSTACKUP:i32 (timm:i32):$amt1, (timm:i32):$amt2)
/*81*/      /*SwitchOpcode*/ 78, TARGET_VAL(ISD::ADD),// ->162
/*84*/        OPC_Scope, 21, /*->107*/ // 3 children in Scope
/*86*/          OPC_RecordChild0, // #0 = $src1
/*87*/          OPC_RecordChild1, // #1 = $imm
/*88*/          OPC_MoveChild, 1,
/*90*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*93*/          OPC_CheckPredicate, 4, // Predicate_TOYimm8
/*95*/          OPC_MoveParent,
/*96*/          OPC_EmitConvertToTarget, 1,
/*98*/          OPC_MorphNodeTo, TARGET_VAL(TOY::ADDri), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (add:i32 i32:i32:$src1, (imm:i32)<<P:Predicate_TOYimm8>>:$imm) - Complexity = 7
                // Dst: (ADDri:i32 i32:i32:$src1, (imm:i32):$imm)
/*107*/       /*Scope*/ 19, /*->127*/
/*108*/         OPC_MoveChild, 0,
/*110*/         OPC_CheckOpcode, TARGET_VAL(ISD::MUL),
/*113*/         OPC_RecordChild0, // #0 = $src1
/*114*/         OPC_RecordChild1, // #1 = $src2
/*115*/         OPC_MoveParent,
/*116*/         OPC_RecordChild1, // #2 = $src3
/*117*/         OPC_MorphNodeTo, TARGET_VAL(TOY::MLA), 0,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 1, 2, 
                // Src: (add:i32 (mul:i32 i32:i32:$src1, i32:i32:$src2), i32:i32:$src3) - Complexity = 6
                // Dst: (MLA:i32 i32:i32:$src1, i32:i32:$src2, i32:i32:$src3)
/*127*/       /*Scope*/ 33, /*->161*/
/*128*/         OPC_RecordChild0, // #0 = $src3
/*129*/         OPC_Scope, 18, /*->149*/ // 2 children in Scope
/*131*/           OPC_MoveChild, 1,
/*133*/           OPC_CheckOpcode, TARGET_VAL(ISD::MUL),
/*136*/           OPC_RecordChild0, // #1 = $src1
/*137*/           OPC_RecordChild1, // #2 = $src2
/*138*/           OPC_MoveParent,
/*139*/           OPC_MorphNodeTo, TARGET_VAL(TOY::MLA), 0,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 1, 2, 0, 
                  // Src: (add:i32 i32:i32:$src3, (mul:i32 i32:i32:$src1, i32:i32:$src2)) - Complexity = 6
                  // Dst: (MLA:i32 i32:i32:$src1, i32:i32:$src2, i32:i32:$src3)
/*149*/         /*Scope*/ 10, /*->160*/
/*150*/           OPC_RecordChild1, // #1 = $src2
/*151*/           OPC_MorphNodeTo, TARGET_VAL(TOY::ADDrr), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (add:i32 i32:i32:$src1, i32:i32:$src2) - Complexity = 3
                  // Dst: (ADDrr:i32 i32:i32:$src1, i32:i32:$src2)
/*160*/         0, /*End of Scope*/
/*161*/       0, /*End of Scope*/
/*162*/     /*SwitchOpcode*/ 34, TARGET_VAL(ISD::SUB),// ->199
/*165*/       OPC_RecordChild0, // #0 = $src1
/*166*/       OPC_RecordChild1, // #1 = $imm
/*167*/       OPC_Scope, 19, /*->188*/ // 2 children in Scope
/*169*/         OPC_MoveChild, 1,
/*171*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*174*/         OPC_CheckPredicate, 4, // Predicate_TOYimm8
/*176*/         OPC_MoveParent,
/*177*/         OPC_EmitConvertToTarget, 1,
/*179*/         OPC_MorphNodeTo, TARGET_VAL(TOY::SUBri), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (sub:i32 i32:i32:$src1, (imm:i32)<<P:Predicate_TOYimm8>>:$imm) - Complexity = 7
                // Dst: (SUBri:i32 i32:i32:$src1, (imm:i32):$imm)
/*188*/       /*Scope*/ 9, /*->198*/
/*189*/         OPC_MorphNodeTo, TARGET_VAL(TOY::SUBrr), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (sub:i32 i32:i32:$src1, i32:i32:$src2) - Complexity = 3
                // Dst: (SUBrr:i32 i32:i32:$src1, i32:i32:$src2)
/*198*/       0, /*End of Scope*/
/*199*/     /*SwitchOpcode*/ 17, TARGET_VAL(TOYISD::MOVEi32),// ->219
/*202*/       OPC_RecordChild0, // #0 = $src
/*203*/       OPC_MoveChild, 0,
/*205*/       OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*208*/       OPC_MoveParent,
/*209*/       OPC_EmitConvertToTarget, 0,
/*211*/       OPC_MorphNodeTo, TARGET_VAL(TOY::MOVi32), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
              // Src: (movei32:i32 (imm:i32):$src) - Complexity = 6
              // Dst: (MOVi32:i32 (imm:i32):$src)
/*219*/     /*SwitchOpcode*/ 15, TARGET_VAL(TOYISD::LOAD_SYM),// ->237
/*222*/       OPC_RecordChild0, // #0 = $addr
/*223*/       OPC_MoveChild, 0,
/*225*/       OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalAddress),
/*228*/       OPC_MoveParent,
/*229*/       OPC_MorphNodeTo, TARGET_VAL(TOY::MOVi32), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (load_sym:i32 (tglobaladdr:i32):$addr) - Complexity = 6
              // Dst: (MOVi32:i32 ?:i32:$addr)
/*237*/     /*SwitchOpcode*/ 17, TARGET_VAL(ISD::CALLSEQ_START),// ->257
/*240*/       OPC_RecordNode, // #0 = 'callseq_start' chained node
/*241*/       OPC_RecordChild1, // #1 = $amt
/*242*/       OPC_MoveChild, 1,
/*244*/       OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*247*/       OPC_MoveParent,
/*248*/       OPC_EmitMergeInputChains1_0,
/*249*/       OPC_MorphNodeTo, TARGET_VAL(TOY::ADJCALLSTACKDOWN), 0|OPFL_Chain|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
              // Src: (callseq_start (timm:i32):$amt) - Complexity = 6
              // Dst: (ADJCALLSTACKDOWN:i32 (timm:i32):$amt)
/*257*/     /*SwitchOpcode*/ 13, TARGET_VAL(ISD::Constant),// ->273
/*260*/       OPC_RecordNode, // #0 = $imm
/*261*/       OPC_CheckPredicate, 5, // Predicate_i32imm_lo
/*263*/       OPC_EmitConvertToTarget, 0,
/*265*/       OPC_MorphNodeTo, TARGET_VAL(TOY::MOVLOi16), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
              // Src: (imm:i32)<<P:Predicate_i32imm_lo>>:$imm - Complexity = 4
              // Dst: (MOVLOi16:i32 (imm:i32):$imm)
/*273*/     /*SwitchOpcode*/ 11, TARGET_VAL(ISD::MUL),// ->287
/*276*/       OPC_RecordChild0, // #0 = $src1
/*277*/       OPC_RecordChild1, // #1 = $src2
/*278*/       OPC_MorphNodeTo, TARGET_VAL(TOY::MUL), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (mul:i32 i32:i32:$src1, i32:i32:$src2) - Complexity = 3
              // Dst: (MUL:i32 i32:i32:$src1, i32:i32:$src2)
/*287*/     /*SwitchOpcode*/ 9, TARGET_VAL(TOYISD::RET_FLAG),// ->299
/*290*/       OPC_RecordNode, // #0 = 'TOYRetFlag' chained node
/*291*/       OPC_CaptureGlueInput,
/*292*/       OPC_EmitMergeInputChains1_0,
/*293*/       OPC_MorphNodeTo, TARGET_VAL(TOY::RET), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic0,
                  0/*#VTs*/, 0/*#Ops*/, 
              // Src: (TOYRetFlag) - Complexity = 3
              // Dst: (RET)
/*299*/     /*SwitchOpcode*/ 13, TARGET_VAL(TOYISD::CALL),// ->315
/*302*/       OPC_RecordNode, // #0 = 'toy_call' chained node
/*303*/       OPC_CaptureGlueInput,
/*304*/       OPC_RecordChild1, // #1 = $addr
/*305*/       OPC_CheckChild1Type, MVT::i32,
/*307*/       OPC_EmitMergeInputChains1_0,
/*308*/       OPC_MorphNodeTo, TARGET_VAL(TOY::BL), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (toy_call i32:i32:$addr) - Complexity = 3
              // Dst: (BL i32:i32:$addr)
/*315*/     0, // EndSwitchOpcode
    0
  }; // Total Array size is 317 bytes

  // Opcode Histogram:
  // #OPC_Scope                          = 3
  // #OPC_RecordNode                     = 7
  // #OPC_RecordChild                    = 22
  // #OPC_RecordMemRef                   = 2
  // #OPC_CaptureGlueInput               = 3
  // #OPC_MoveChild                      = 9
  // #OPC_MoveParent                     = 9
  // #OPC_CheckSame                      = 0
  // #OPC_CheckChildSame                 = 0
  // #OPC_CheckPatternPredicate          = 0
  // #OPC_CheckPredicate                 = 7
  // #OPC_CheckOpcode                    = 9
  // #OPC_SwitchOpcode                   = 1
  // #OPC_CheckType                      = 1
  // #OPC_SwitchType                     = 0
  // #OPC_CheckChildType                 = 2
  // #OPC_CheckInteger                   = 0
  // #OPC_CheckChildInteger              = 0
  // #OPC_CheckCondCode                  = 0
  // #OPC_CheckValueType                 = 0
  // #OPC_CheckComplexPat                = 2
  // #OPC_CheckAndImm                    = 0
  // #OPC_CheckOrImm                     = 0
  // #OPC_CheckFoldableChainNode         = 0
  // #OPC_EmitInteger                    = 0
  // #OPC_EmitStringInteger              = 0
  // #OPC_EmitRegister                   = 0
  // #OPC_EmitConvertToTarget            = 4
  // #OPC_EmitMergeInputChains           = 6
  // #OPC_EmitCopyToReg                  = 0
  // #OPC_EmitNode                       = 0
  // #OPC_EmitNodeXForm                  = 0
  // #OPC_MarkGlueResults                = 0
  // #OPC_CompleteMatch                  = 0
  // #OPC_MorphNodeTo                    = 16

  #undef TARGET_VAL
  return SelectCodeCommon(N, MatcherTable,sizeof(MatcherTable));
}

bool CheckNodePredicate(SDNode *Node,
                        unsigned PredNo) const override {
  switch (PredNo) {
  default: llvm_unreachable("Invalid predicate in table?");
  case 0: { // Predicate_unindexedload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 1: { // Predicate_load
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::NON_EXTLOAD;

  }
  case 2: { // Predicate_unindexedstore
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 3: { // Predicate_store
    SDNode *N = Node;

  return !cast<StoreSDNode>(N)->isTruncatingStore();

  }
  case 4: { // Predicate_TOYimm8
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();

  return Imm >= 0 && Imm < 256;

  }
  case 5: { // Predicate_i32imm_lo
    int64_t Imm = cast<ConstantSDNode>(Node)->getSExtValue();

  return Imm >= 0 && Imm < 65536;

  }
  }
}

bool CheckComplexPattern(SDNode *Root, SDNode *Parent,
                         SDValue N, unsigned PatternNo,
         SmallVectorImpl<std::pair<SDValue, SDNode*> > &Result) override {
  unsigned NextRes = Result.size();
  switch (PatternNo) {
  default: llvm_unreachable("Invalid pattern # in table?");
  case 0:
    Result.resize(NextRes+2);
    return SelectAddr(N, Result[NextRes+0].first, Result[NextRes+1].first);
  }
}

