
#include <benchmark/benchmark.h>

#include "include/factorial.hpp"

volatile std::string *_sink;

static void BM_factorial1000(benchmark::State &state) {
  for (auto _ : state) {
    auto b = factorial(1000);
    asm volatile("" ::: "memory");
    _sink = &b;
  }
}
BENCHMARK(BM_factorial1000);

static void BM_factorial5000(benchmark::State &state) {
  for (auto _ : state) {
    auto b = factorial(5000);
    asm volatile("" ::: "memory");
    _sink = &b;
  }
}
BENCHMARK(BM_factorial5000);

static void BM_factorial10000(benchmark::State &state) {
  for (auto _ : state) {
    auto b = factorial(10000);
    asm volatile("" ::: "memory");
    _sink = &b;
  }
}
BENCHMARK(BM_factorial10000);

static void BM_factorial50000(benchmark::State &state) {
  for (auto _ : state) {
    auto b = factorial(50000);
    asm volatile("" ::: "memory");
    _sink = &b;
  }
}
BENCHMARK(BM_factorial50000);

static void BM_factorial80000(benchmark::State &state) {
  for (auto _ : state) {
    auto b = factorial(80000);
    asm volatile("" ::: "memory");
    _sink = &b;
  }
}
BENCHMARK(BM_factorial80000);

static void BM_factorial100000(benchmark::State &state) {
  for (auto _ : state) {
    auto b = factorial(100000);
    asm volatile("" ::: "memory");
    _sink = &b;
  }
}
BENCHMARK(BM_factorial100000);

BENCHMARK_MAIN();
