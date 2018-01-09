FILE(REMOVE_RECURSE
  "LEGGenRegisterInfo.inc.tmp"
  "LEGGenRegisterInfo.inc"
  "LEGGenInstrInfo.inc.tmp"
  "LEGGenInstrInfo.inc"
  "LEGGenAsmWriter.inc.tmp"
  "LEGGenAsmWriter.inc"
  "LEGGenDAGISel.inc.tmp"
  "LEGGenDAGISel.inc"
  "LEGGenCallingConv.inc.tmp"
  "LEGGenCallingConv.inc"
  "LEGGenSubtargetInfo.inc.tmp"
  "LEGGenSubtargetInfo.inc"
  "LEGGenMCCodeEmitter.inc.tmp"
  "LEGGenMCCodeEmitter.inc"
  "CMakeFiles/LEGCommonTableGen"
  "LEGGenRegisterInfo.inc"
  "LEGGenInstrInfo.inc"
  "LEGGenAsmWriter.inc"
  "LEGGenDAGISel.inc"
  "LEGGenCallingConv.inc"
  "LEGGenSubtargetInfo.inc"
  "LEGGenMCCodeEmitter.inc"
  "LEGGenRegisterInfo.inc.tmp"
  "LEGGenInstrInfo.inc.tmp"
  "LEGGenAsmWriter.inc.tmp"
  "LEGGenDAGISel.inc.tmp"
  "LEGGenCallingConv.inc.tmp"
  "LEGGenSubtargetInfo.inc.tmp"
  "LEGGenMCCodeEmitter.inc.tmp"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/LEGCommonTableGen.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
