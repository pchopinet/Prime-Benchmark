cmake_minimum_required(VERSION 3.9)
project(Prime_Benchmark)

set(CMAKE_CXX_STANDARD 11)

add_executable(Prime_Benchmark
        cpp/main.cpp
        cs/Program.cs
        cuda/cuda.cu
        go/main.go
        java/Alternative.java
        java/main.java
        py/main.py
        rust/main.rs
        LICENSE.md
        README.md)
