project(factorial)

cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

include(FetchContent)
include(src/CMakeLists.txt)

# Fetch google-test and build unittest executable
FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1)
FetchContent_MakeAvailable(googletest)
add_executable(unittest_${CMAKE_PROJECT_NAME} unittest.cpp)
target_link_libraries(unittest_${CMAKE_PROJECT_NAME} gtest_main src)
add_test(NAME unittest_${CMAKE_PROJECT_NAME} COMMAND unittest_${CMAKE_PROJECT_NAME})
enable_testing()

# Fetch google-benchmark and build benchmark executable
set(BENCHMARK_ENABLE_TESTING OFF) # Disable testing of benchmark library
FetchContent_Declare(googlebenchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG v1.7.0)
FetchContent_MakeAvailable(googlebenchmark)
add_executable(bench_${CMAKE_PROJECT_NAME} bench.cpp)
target_link_libraries(bench_${CMAKE_PROJECT_NAME} src benchmark)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} src)
