TO INSTALL LLVM AND RUN TOY COMPILER ON EXAMPLE FILES:



1. Open Terminal. Install cmake
 
$ sudo apt-get install cmake
 
2. Install libxml2-dev
 
$ sudo apt-get install libxml2-dev
 
3. create directory Opensource
 
$ mkdir Opensource
 
4. go into that directory
 
$ cd Opensource
 
5. Install svn
 
$ sudo apt-get install svn
 
6. Download LLVM source code
 
$ svn co http://llvm.org/svn/llvm-project/llvm/trunk llvm
 
7. go into tools folder
 
$ cd llvm/tools
 
8. Download CLANG
 
$ svn co http://llvm.org/svn/llvm-project/cfe/trunk clang
 
9. Come back to original LLVM directory
 
$ cd ../..
 
10. make a build directory
 
$ mkdir build
 
11. go into build directory
 
$ cd build
 
12. configure llvm
 
$ cmake ../ -DCMAKE_BUILD_TYPE=Release -DLLVM_TARGETS_TO_BUILD="X86;ARM"
 
13. build llvm and clang
 
$ make
 
14. Go to home directory
 
$ cd
 
15. Place ch2_toy.cpp file in the home directory
 
16. Compile the ch2_toy.cpp file
 
$ Opensource/llvm/build/bin/clang++ -g ch2_toy.cpp `Opensource/llvm/build/bin/llvm-config --cxxflags --ldflags --system-libs --libs core mcjit native` -O3 -o toy
 
17. Run toy with example files
 
$ ./toy example1