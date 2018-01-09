/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Machine Code Emitter                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

uint64_t TOYMCCodeEmitter::getBinaryCodeForInstr(const MCInst &MI,
    SmallVectorImpl<MCFixup> &Fixups,
    const MCSubtargetInfo &STI) const {
  static const uint64_t InstBits[] = {
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(3800039424),	// ADDri
    UINT64_C(3766484992),	// ADDrr
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(3942645760),	// BL
    UINT64_C(3851419648),	// LDR
    UINT64_C(3760193680),	// MLA
    UINT64_C(3812622336),	// MOVHIi16
    UINT64_C(3808428032),	// MOVLOi16
    UINT64_C(0),
    UINT64_C(3785359360),	// MOVrr
    UINT64_C(3758096528),	// MUL
    UINT64_C(3778019102),	// RET
    UINT64_C(3850371072),	// STR
    UINT64_C(3795845120),	// SUBri
    UINT64_C(3762290688),	// SUBrr
    UINT64_C(0)
  };
  const unsigned opcode = MI.getOpcode();
  uint64_t Value = InstBits[opcode];
  uint64_t op = 0;
  (void)op;  // suppress warning
  switch (opcode) {
    case TOY::RET: {
      break;
    }
    case TOY::BL: {
      // op: addr
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= op & UINT64_C(15);
      break;
    }
    case TOY::STR: {
      // op: addr
      op = getMemSrcValue(MI, 1, Fixups, STI);
      Value |= (op & UINT64_C(61440)) << 4;
      Value |= op & UINT64_C(4095);
      // op: val
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 12;
      break;
    }
    case TOY::MOVLOi16: {
      // op: dst
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 12;
      // op: imm
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      Value |= (op & UINT64_C(61440)) << 4;
      Value |= op & UINT64_C(4095);
      break;
    }
    case TOY::MOVHIi16: {
      // op: dst
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 12;
      // op: imm
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      Value |= (op & UINT64_C(61440)) << 4;
      Value |= op & UINT64_C(4095);
      break;
    }
    case TOY::MOVrr: {
      // op: dst
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 12;
      // op: src
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      Value |= op & UINT64_C(15);
      break;
    }
    case TOY::ADDrr:
    case TOY::SUBrr: {
      // op: dst
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 12;
      // op: src1
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 16;
      // op: src2
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      Value |= op & UINT64_C(15);
      break;
    }
    case TOY::ADDri:
    case TOY::SUBri: {
      // op: dst
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 16;
      // op: src1
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 12;
      // op: imm
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      Value |= op & UINT64_C(4095);
      break;
    }
    case TOY::MUL: {
      // op: dst
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 16;
      // op: src1
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      Value |= op & UINT64_C(15);
      // op: src2
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 8;
      break;
    }
    case TOY::MLA: {
      // op: dst
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 16;
      // op: src1
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      Value |= op & UINT64_C(15);
      // op: src2
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 8;
      // op: src3
      op = getMachineOpValue(MI, MI.getOperand(3), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 12;
      break;
    }
    case TOY::LDR: {
      // op: val
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 12;
      // op: addr
      op = getMemSrcValue(MI, 1, Fixups, STI);
      Value |= (op & UINT64_C(61440)) << 4;
      Value |= op & UINT64_C(4095);
      break;
    }
  default:
    std::string msg;
    raw_string_ostream Msg(msg);
    Msg << "Not supported instr: " << MI;
    report_fatal_error(Msg.str());
  }
  return Value;
}

