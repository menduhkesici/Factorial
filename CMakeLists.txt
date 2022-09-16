project(factorial)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
include(FetchContent)

# Fetch google-test
FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1)
FetchContent_MakeAvailable(googletest)

# Fetch google-benchmark
FetchContent_Declare(googlebenchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG v1.7.0)
FetchContent_MakeAvailable(googlebenchmark)

include(src/CMakeLists.txt)

add_executable(${CMAKE_PROJECT_NAME}_unittest ${CMAKE_PROJECT_NAME}_unittest.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_unittest gtest_main src)
add_test(NAME ${CMAKE_PROJECT_NAME}_test COMMAND ${CMAKE_PROJECT_NAME}_unittest)
enable_testing()

add_executable(${CMAKE_PROJECT_NAME}_bench ${CMAKE_PROJECT_NAME}_bench.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_bench src benchmark)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} src)
