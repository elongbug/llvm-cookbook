FILE(REMOVE_RECURSE
  "TOYGenRegisterInfo.inc.tmp"
  "TOYGenRegisterInfo.inc"
  "TOYGenInstrInfo.inc.tmp"
  "TOYGenInstrInfo.inc"
  "TOYGenAsmWriter.inc.tmp"
  "TOYGenAsmWriter.inc"
  "TOYGenDAGISel.inc.tmp"
  "TOYGenDAGISel.inc"
  "TOYGenCallingConv.inc.tmp"
  "TOYGenCallingConv.inc"
  "TOYGenSubtargetInfo.inc.tmp"
  "TOYGenSubtargetInfo.inc"
  "TOYGenMCCodeEmitter.inc.tmp"
  "TOYGenMCCodeEmitter.inc"
  "CMakeFiles/LLVMTOYCodeGen.dir/TOYSubtarget.cpp.o"
  "CMakeFiles/LLVMTOYCodeGen.dir/TOYTargetMachine.cpp.o"
  "CMakeFiles/LLVMTOYCodeGen.dir/TOYRegisterInfo.cpp.o"
  "CMakeFiles/LLVMTOYCodeGen.dir/TOYInstrInfo.cpp.o"
  "CMakeFiles/LLVMTOYCodeGen.dir/TOYFrameLowering.cpp.o"
  "CMakeFiles/LLVMTOYCodeGen.dir/TOYISelLowering.cpp.o"
  "CMakeFiles/LLVMTOYCodeGen.dir/TOYSelectionDAGInfo.cpp.o"
  "CMakeFiles/LLVMTOYCodeGen.dir/TOYISelDAGToDAG.cpp.o"
  "CMakeFiles/LLVMTOYCodeGen.dir/TOYAsmPrinter.cpp.o"
  "CMakeFiles/LLVMTOYCodeGen.dir/TOYMCInstLower.cpp.o"
  "../../libLLVMTOYCodeGen.pdb"
  "../../libLLVMTOYCodeGen.a"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang CXX)
  INCLUDE(CMakeFiles/LLVMTOYCodeGen.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
