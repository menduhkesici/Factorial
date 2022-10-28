
#include <benchmark/benchmark.h>

#include "include/factorial.hpp"

static void BM_factorial1000(benchmark::State &state) {
  for (auto _ : state) {
    auto result = factorial(1000);
  }
}
BENCHMARK(BM_factorial1000);

static void BM_factorial5000(benchmark::State &state) {
  for (auto _ : state) {
    auto result = factorial(5000);
  }
}
BENCHMARK(BM_factorial5000);

static void BM_factorial10000(benchmark::State &state) {
  for (auto _ : state) {
    auto result = factorial(10000);
  }
}
BENCHMARK(BM_factorial10000);

static void BM_factorial50000(benchmark::State &state) {
  for (auto _ : state) {
    auto result = factorial(50000);
  }
}
BENCHMARK(BM_factorial50000);

static void BM_factorial80000(benchmark::State &state) {
  for (auto _ : state) {
    auto result = factorial(80000);
  }
}
BENCHMARK(BM_factorial80000);

static void BM_factorial100000(benchmark::State &state) {
  for (auto _ : state) {
    auto result = factorial(100000);
  }
}
BENCHMARK(BM_factorial100000);

BENCHMARK_MAIN();
