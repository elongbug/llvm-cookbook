CHAPTER 1:
All the required tools to execute the test codes are present in the folder. Install them into your path or use ./tool_name
make a softlink for clang-3.7 named as clang, or replace clang by clang-3.7 in the examples below.
The outputs for each example are present in the dorectory.

Recipe : Understanding modular design
compile using the command:
opt -S -instcombine understanding_modular_design.ll -o output1.ll

opt -S -deadargelim understanding_modular_design.ll -o output1.ll


Recipe : Coverting C code to LLVM Assembly
clang -emit-llvm -S c_code_to_ir.c -o output2.ll


Recipe: Converting IR to LLVM Bit Code
llvm-as ir_to_bc.ll -o output3.bc


Recipe: Converting LLVM Bitcode to Target Machine Assembly
llc bc_to_target_assembly.bc -o output4.s


Recipe: Converting LLVM Bitode back to LLVM Assembly
llvm-dis bc_to_target_assembly.bc -o output5.ll


Recipe: Transforming LLVM IR
clang -emit-llvm -S transform.c -o transform.ll

opt -mem2reg -S transform.ll -o output6.ll


Recipe: Linking LLVM Bitcode 
clang -emit-llvm -S linking1.c -o linking1.ll
clang -emit-llvm -S linking2.c -o linking2.ll

llvm-as linking1.ll -o linking1.bc
llvm-as linking2.ll -o linking2.bc

llvm-link linking1.bc linking2.bc -o output7.bc


Recipe: Executing LLVM Bitcode
lli output7.bc


Recipe: Using the C frontend clang
clang c_frontend.c

clang c_frontend_1.c -E

clang -cc1 c_frontend_1.c -ast-dump

clang c_frontend_1.c -S -emit-llvm -o -

clang -S c_frontend_1.c -o -

