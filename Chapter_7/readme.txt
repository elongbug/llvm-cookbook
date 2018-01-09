CHAPTER 7:

Recipe : Analyzing Live Interval
Build LLVM by replacing /home/mayur/LLVMSVN_REV/llvm/llvm/lib/CodeGen/LiveIntervalAnalysis.cpp with LiveIntervalAnalysis.cpp in code bundle. This will give the new llc tool, which is also present in the code bundle.
clang -cc1 -emit-llvm interval.c
llc interval.ll


Recipe: Register Allocation
remove the changes made in LiveVariableAnalysis.cpp file and build again to get the llc tool as it was earlier.
now use interval.ll file which was output of previous recipe as the input to llc. In code bundle i have renamed normal llc tool as llc1.
llc -regalloc=basic interval.ll -o intervalregbasic.s


Recipe : Tail Call Optimization
use the normal llc , llc1 in the code bundle.
./llc1 -tailcallopt tailcall.ll
./llc1  tailcall.ll -o tailcall1.s


Recipe : Sibling Call Optimisation
use normal llc, llc1 in the code bundle.
./llc1 sibcall.ll

