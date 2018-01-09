CHAPTER 5:

Recipe: Writing Dead Code Elimination Pass
Download LLVM code using svn:
Replace the files:
include/llvm/InitializePasses.h with InitializePasses-adce.h in the code bundle
include/llvm-c/Transform/scalar.h with scalar1.h in code bundle and then rename it to scalar.h
include/llvm/Transform/scalar.h with scalar2.h in code bundle and rename it to scalar.h
lib/Transforms/Scalar/scalar.cpp with scalar.cpp in code bundle
lib/Transforms/Scalar/CMakeLists.txt with CMakeLists-adce.txt in the code bundle.

Add the file: lib/Transforms/Scalar/MYACDE.cpp

build llvm making necessary and you get the opt tool(present in code bundle) with myadce pass.

execute the follwing command to run the myadce pass.
opt -myadce -S deadcodeelim.ll 


Recipe: Writing an inline transformation pass
Replace the files:
include/llvm/InitializePasses.h with InitializePasses-inliner.h in the code bundle
lib/Transforms/IPO/IPO.cpp with IPO.cpp in code bundle
include/llvm/Transforms/IPO.h with IPO1.h
lib/Transforms/IPO/CMakeLists.txt with CMakeLists-inliner.txt in the code bundle.

add the file lib/Transforms/IPO/myinline.cpp

build llvm making necessary and you get the opt tool(present in code bundle as opt1) with my-inline pass.
execute the following command
opt -inline-threshold=0 -my-inline -S inline.ll


Recipe: Memory Optimization:
pleae note: the testcode in recipe of book needs to be modified as some implementation have changed for accessing array through getelementptr. The modifed code is in code bundle.
opt -memcpyopt -S memcopytest.ll



Recipe : Combining IR
please not: in recipe there is one missed { after the if condition. Also some minor code modification required as the earlier modifications dont catch the testcode. the modified version is in the InstCombineAndOrXor.cpp. added that in the code bundle.
replace /home/mayur/LLVMSVN_REV/llvm/llvm/lib/Transforms/InstCombine/InstCombineAndOrXor.cpp with the InstCombineAndOrXor.cpp present in the code bundle.
opt -instcombine -S instcombine.ll



Recipe : Testing loops:
opt licmtest.ll -licm -S

opt deletetest.ll -loop-deletion -S


Recipe : Reassociate
opt testreassociate.ll  -reassociate -die -S


Recipe : Other optimization passes
opt -strip-debug teststripdebug.ll  -S
opt -prune-eh -S simpletest.ll
