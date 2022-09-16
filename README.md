# C++ Factorial

C++ program to calculate factorial of a number

It includes CMake build system, unit testing and benchmarking.

## Build

Building requires google-benchmark and google-test.
They are fetched by cmake.

Install prerequisites on Ubuntu/Debian:
```
sudo apt-get install libbenchmark-dev cmake
```

Build:
```
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make
```

Test:
```
./factorial_unittest
```

Benchmark:
```
./factorial_bench
```

Run main application:
```
./factorial 10
```
