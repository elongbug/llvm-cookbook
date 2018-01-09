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
  "CMakeFiles/TOYCommonTableGen"
  "TOYGenRegisterInfo.inc"
  "TOYGenInstrInfo.inc"
  "TOYGenAsmWriter.inc"
  "TOYGenDAGISel.inc"
  "TOYGenCallingConv.inc"
  "TOYGenSubtargetInfo.inc"
  "TOYGenMCCodeEmitter.inc"
  "TOYGenRegisterInfo.inc.tmp"
  "TOYGenInstrInfo.inc.tmp"
  "TOYGenAsmWriter.inc.tmp"
  "TOYGenDAGISel.inc.tmp"
  "TOYGenCallingConv.inc.tmp"
  "TOYGenSubtargetInfo.inc.tmp"
  "TOYGenMCCodeEmitter.inc.tmp"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/TOYCommonTableGen.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
