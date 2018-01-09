FILE(REMOVE_RECURSE
  "LLVMHello.exports"
  "CMakeFiles/LLVMHello_exports"
  "LLVMHello.exports"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/LLVMHello_exports.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
