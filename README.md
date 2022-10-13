# C++ Factorial

C++ program with CMake build system, unit-testing and benchmarking to calculate factorial of a number

## Build

CMake fetches google-benchmark and google-test automatically.

Install prerequisites on Ubuntu/Debian:
```
sudo apt-get install cmake
```

Build:
```
mkdir -p build && cd $_
cmake .. -DCMAKE_BUILD_TYPE=Release
make
```

Test:
```
ctest
```

Benchmark:
```
./bench_factorial --benchmark_time_unit=ms
```

Run main application:
```
./factorial 10
```
