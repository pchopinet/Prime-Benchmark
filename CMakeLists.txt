cmake_minimum_required(VERSION 3.9)
project(Prime_Benchmark)

set(CMAKE_CXX_STANDARD 11)

add_executable(Prime_Benchmark
        cpp/main.cpp
        cs/Program.cs
        go/main.go
        java/Alternative.java
        java/prime_java.java
        py/main.py
        rust/main.rs
        LICENSE.md
        README.md opencl/main.cpp)
