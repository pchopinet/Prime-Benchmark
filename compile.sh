CC=clang
CXX=g++
output=prime_

$CXX cpp/main.cpp -O3 -lm -lpthread -o "$output"cpp

nvcc cuda/main.cu -ccbin $CC -use_fast_math -D_FORCE_INLINES -O3 -o "$output"cuda

go build -o "$output"go go/main.go

javac java/main.java -d .
jar cvf "$output"java.jar main.class
rm main.class
