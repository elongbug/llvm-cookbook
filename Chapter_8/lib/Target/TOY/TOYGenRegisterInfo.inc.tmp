/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Target Register Enum Values                                                 *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_ENUM
#undef GET_REGINFO_ENUM
namespace llvm {

class MCRegisterClass;
extern const MCRegisterClass TOYMCRegisterClasses[];

namespace TOY {
enum {
  NoRegister,
  LR = 1,
  SP = 2,
  R0 = 3,
  R1 = 4,
  R2 = 5,
  R3 = 6,
  R4 = 7,
  R5 = 8,
  R6 = 9,
  R7 = 10,
  R8 = 11,
  R9 = 12,
  NUM_TARGET_REGS 	// 13
};
}

// Register classes
namespace TOY {
enum {
  GRRegsRegClassID = 0
  };
}
} // End llvm namespace 
#endif // GET_REGINFO_ENUM

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*MC Register Information                                                     *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_MC_DESC
#undef GET_REGINFO_MC_DESC
namespace llvm {

extern const MCPhysReg TOYRegDiffLists[] = {
  /* 0 */ 65535, 0,
};

extern const uint16_t TOYSubRegIdxLists[] = {
  /* 0 */ 0,
};

extern const MCRegisterInfo::SubRegCoveredBits TOYSubRegIdxRanges[] = {
  { 65535, 65535 },
};

extern const char TOYRegStrings[] = {
  /* 0 */ 'R', '0', 0,
  /* 3 */ 'R', '1', 0,
  /* 6 */ 'R', '2', 0,
  /* 9 */ 'R', '3', 0,
  /* 12 */ 'R', '4', 0,
  /* 15 */ 'R', '5', 0,
  /* 18 */ 'R', '6', 0,
  /* 21 */ 'R', '7', 0,
  /* 24 */ 'R', '8', 0,
  /* 27 */ 'R', '9', 0,
  /* 30 */ 'S', 'P', 0,
  /* 33 */ 'L', 'R', 0,
};

extern const MCRegisterDesc TOYRegDesc[] = { // Descriptors
  { 2, 0, 0, 0, 0 },
  { 33, 1, 1, 0, 1 },
  { 30, 1, 1, 0, 1 },
  { 0, 1, 1, 0, 1 },
  { 3, 1, 1, 0, 1 },
  { 6, 1, 1, 0, 1 },
  { 9, 1, 1, 0, 1 },
  { 12, 1, 1, 0, 1 },
  { 15, 1, 1, 0, 1 },
  { 18, 1, 1, 0, 1 },
  { 21, 1, 1, 0, 1 },
  { 24, 1, 1, 0, 1 },
  { 27, 1, 1, 0, 1 },
};

extern const MCPhysReg TOYRegUnitRoots[][2] = {
  { TOY::LR },
  { TOY::SP },
  { TOY::R0 },
  { TOY::R1 },
  { TOY::R2 },
  { TOY::R3 },
  { TOY::R4 },
  { TOY::R5 },
  { TOY::R6 },
  { TOY::R7 },
  { TOY::R8 },
  { TOY::R9 },
};

namespace {     // Register classes...
  // GRRegs Register Class...
  const MCPhysReg GRRegs[] = {
    TOY::R0, TOY::R1, TOY::R2, TOY::R3, TOY::R4, TOY::R5, TOY::R6, TOY::R7, TOY::R8, TOY::R9, TOY::SP, 
  };

  // GRRegs Bit set.
  const uint8_t GRRegsBits[] = {
    0xfc, 0x1f, 
  };

}

extern const MCRegisterClass TOYMCRegisterClasses[] = {
  { "GRRegs", GRRegs, GRRegsBits, 11, sizeof(GRRegsBits), TOY::GRRegsRegClassID, 4, 4, 1, 1 },
};

extern const uint16_t TOYRegEncodingTable[] = {
  0,
  14,
  13,
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
};
static inline void InitTOYMCRegisterInfo(MCRegisterInfo *RI, unsigned RA, unsigned DwarfFlavour = 0, unsigned EHFlavour = 0, unsigned PC = 0) {
  RI->InitMCRegisterInfo(TOYRegDesc, 13, RA, PC, TOYMCRegisterClasses, 1, TOYRegUnitRoots, 12, TOYRegDiffLists, TOYRegStrings, TOYSubRegIdxLists, 1,
TOYSubRegIdxRanges,   TOYRegEncodingTable);

}

} // End llvm namespace 
#endif // GET_REGINFO_MC_DESC

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Register Information Header Fragment                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_HEADER
#undef GET_REGINFO_HEADER
#include "llvm/Target/TargetRegisterInfo.h"

namespace llvm {

struct TOYGenRegisterInfo : public TargetRegisterInfo {
  explicit TOYGenRegisterInfo(unsigned RA, unsigned D = 0, unsigned E = 0, unsigned PC = 0);
  bool needsStackRealignment(const MachineFunction &) const override
     { return false; }
  const RegClassWeight &getRegClassWeight(const TargetRegisterClass *RC) const override;
  unsigned getRegUnitWeight(unsigned RegUnit) const override;
  unsigned getNumRegPressureSets() const override;
  const char *getRegPressureSetName(unsigned Idx) const override;
  unsigned getRegPressureSetLimit(unsigned Idx) const override;
  const int *getRegClassPressureSets(const TargetRegisterClass *RC) const override;
  const int *getRegUnitPressureSets(unsigned RegUnit) const override;
};

namespace TOY { // Register classes
  extern const TargetRegisterClass GRRegsRegClass;
} // end of namespace TOY

} // End llvm namespace 
#endif // GET_REGINFO_HEADER

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Target Register and Register Classes Information                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_TARGET_DESC
#undef GET_REGINFO_TARGET_DESC
namespace llvm {

extern const MCRegisterClass TOYMCRegisterClasses[];

static const MVT::SimpleValueType VTLists[] = {
  /* 0 */ MVT::i32, MVT::Other,
};

static const char *const SubRegIndexNameTable[] = { "" };


static const unsigned SubRegIndexLaneMaskTable[] = {
  ~0u,
 };



static const TargetRegisterClass *const NullRegClasses[] = { nullptr };

static const uint32_t GRRegsSubClassMask[] = {
  0x00000001, 
};

static const uint16_t SuperRegIdxSeqs[] = {
  /* 0 */ 0,
};

namespace TOY {   // Register class instances
  extern const TargetRegisterClass GRRegsRegClass = {
    &TOYMCRegisterClasses[GRRegsRegClassID],
    VTLists + 0,
    GRRegsSubClassMask,
    SuperRegIdxSeqs + 0,
    NullRegClasses,
    nullptr
  };

}

namespace {
  const TargetRegisterClass* const RegisterClasses[] = {
    &TOY::GRRegsRegClass,
  };
}

static const TargetRegisterInfoDesc TOYRegInfoDesc[] = { // Extra Descriptors
  { 0, 0 },
  { 0, 0 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
};
/// Get the weight in units of pressure for this register class.
const RegClassWeight &TOYGenRegisterInfo::
getRegClassWeight(const TargetRegisterClass *RC) const {
  static const RegClassWeight RCWeightTable[] = {
    {1, 11},  	// GRRegs
    {0, 0} };
  return RCWeightTable[RC->getID()];
}

/// Get the weight in units of pressure for this register unit.
unsigned TOYGenRegisterInfo::
getRegUnitWeight(unsigned RegUnit) const {
  assert(RegUnit < 12 && "invalid register unit");
  // All register units have unit weight.
  return 1;
}


// Get the number of dimensions of register pressure.
unsigned TOYGenRegisterInfo::getNumRegPressureSets() const {
  return 1;
}

// Get the name of this register unit pressure set.
const char *TOYGenRegisterInfo::
getRegPressureSetName(unsigned Idx) const {
  static const char *PressureNameTable[] = {
    "GRRegs",
    nullptr };
  return PressureNameTable[Idx];
}

// Get the register unit pressure limit for this dimension.
// This limit must be adjusted dynamically for reserved registers.
unsigned TOYGenRegisterInfo::
getRegPressureSetLimit(unsigned Idx) const {
  static const unsigned PressureLimitTable[] = {
    11,  	// 0: GRRegs
    0 };
  return PressureLimitTable[Idx];
}

/// Table of pressure sets per register class or unit.
static const int RCSetsTable[] = {
    0,  -1,  	// #0 GRRegs
    -1,  	// #2 inferred
    -1 };

/// Get the dimensions of register pressure impacted by this register class.
/// Returns a -1 terminated array of pressure set IDs
const int* TOYGenRegisterInfo::
getRegClassPressureSets(const TargetRegisterClass *RC) const {
  static const unsigned RCSetStartTable[] = {
    0,0 };
  unsigned SetListStart = RCSetStartTable[RC->getID()];
  return &RCSetsTable[SetListStart];
}

/// Get the dimensions of register pressure impacted by this register unit.
/// Returns a -1 terminated array of pressure set IDs
const int* TOYGenRegisterInfo::
getRegUnitPressureSets(unsigned RegUnit) const {
  assert(RegUnit < 12 && "invalid register unit");
  static const unsigned RUSetStartTable[] = {
    2,0,0,0,0,0,0,0,0,0,0,0,0 };
  unsigned SetListStart = RUSetStartTable[RegUnit];
  return &RCSetsTable[SetListStart];
}

extern const MCRegisterDesc TOYRegDesc[];
extern const MCPhysReg TOYRegDiffLists[];
extern const char TOYRegStrings[];
extern const MCPhysReg TOYRegUnitRoots[][2];
extern const uint16_t TOYSubRegIdxLists[];
extern const MCRegisterInfo::SubRegCoveredBits TOYSubRegIdxRanges[];
extern const uint16_t TOYRegEncodingTable[];
TOYGenRegisterInfo::
TOYGenRegisterInfo(unsigned RA, unsigned DwarfFlavour, unsigned EHFlavour, unsigned PC)
  : TargetRegisterInfo(TOYRegInfoDesc, RegisterClasses, RegisterClasses+1,
             SubRegIndexNameTable, SubRegIndexLaneMaskTable, 0xffffffff) {
  InitMCRegisterInfo(TOYRegDesc, 13, RA, PC,
                     TOYMCRegisterClasses, 1,
                     TOYRegUnitRoots,
                     12,
                     TOYRegDiffLists,
                     TOYRegStrings,
                     TOYSubRegIdxLists,
                     1,
                     TOYSubRegIdxRanges,
                     TOYRegEncodingTable);

}

static const MCPhysReg CC_Save_SaveList[] = { TOY::R4, TOY::R5, TOY::R6, TOY::R7, TOY::R8, TOY::R9, 0 };
static const uint32_t CC_Save_RegMask[] = { 0x00001f80, };


} // End llvm namespace 
#endif // GET_REGINFO_TARGET_DESC

