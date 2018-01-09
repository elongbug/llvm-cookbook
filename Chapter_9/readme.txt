CHAPTER 9

Recipe: Exception Handling in LLVM
clang -c eh.cpp -emit-llvm -o eh.bc

llvm-dis eh.bc -o -


Recipe : Using Sanitizers
clang -fsanitize=address asan.c 
the above command will look for runtime library libclang_rt.asan-x86_64.a, it should be installed. else u can use -L"path-to-runtime-lib" -lclang_rt.asan-x86_64 as the additional options.

ASAN_SYMBOLIZER_PATH=/usr/local/bin/llvm-symbolizer ./a.out
llvm-symbolizer must be installed to usr/local/bin else give absolute path.


Recipe : Garbage Collection
llc testgc.ll
cat testgc.s


Recipe : Converting LLVM IR to Javascript
Install emscripten using the package in the code bundle. there r many dependencies which need to be fullfilled to run this tool
emsdk_portable/emscripten/master/./emcc emscripten.c -o emscripten.bc
/home/mayur/Downloads/emsdk_portable/emscripten/master/./emcc emscripten.bc
nodejs a.out.js



Recipe : Using clang static analyzer
clang -cc1 -analyze -analyzer-checker=core.DivideZero sa.c


Recipe : Using Bugpoint
bugpoint -load  ~/LLVMSVN_REV/llvm/llvm/dbuild/./lib/BugpointPasses.so crash-narrowfunctiontest.ll -output-prefix crash-narrowfunctiontest.ll.tmp -bugpoint-crashcalls -silence-passes

BugpointPasses.so is present in the code bundle. You can use that.
To see the reduced testcase execute the following commands:

llvm-dis crash-narrowfunctiontest.ll.tmp-reduced-simplified.bc
cat crash-narrowfunctiontest.ll.tmp-reduced-simplified.ll


Recipe : Using LLDB
compile code with debug info:
clang -g lldbexample.c
run lldb on executable
 lldb a.out 
now u can test the working by setting breakpoints, running the executable, putting watchpoint etc.

In the code bundle lldb-3.7.0 is present. make a softlink to it named lldb or u can directly use this lldb as well.


Recipe : Using Utility Passes
 opt -view-cfg-only utility.ll

opt -view-dom utility.ll

