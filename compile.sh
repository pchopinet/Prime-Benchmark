#!/bin/bash

CC=clang-3.8
CXX=g++
output=prime_

set -x

$CXX cpp/main.cpp -std=c++11 -O3 -lm -lpthread -o "$output"cpp

$CXX omp/main.cpp -std=c++11 -O3 -lm -fopenmp -o "$output"omp

nvcc cuda/main.cu -ccbin $CC -use_fast_math -D_FORCE_INLINES -O3 -o "$output"cuda

rustc rust/main.rs -C opt-level=3 -o "$output"rust

go build -o "$output"go go/main.go

javac java/prime_java.java -d .
