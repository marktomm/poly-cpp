#include <benchmark/benchmark.h>

// DoNotOptimize
static void escape(void *p) {
    asm volatile("" : : "g"(p) : "memory");
}

// ClobberMemory
static void clobber() {
    asm volatile("" : : : "memory");
}

void SomeFunction() {
    int a = 1;
    int b = 2;
    int c = 0;

    // https://youtu.be/nXaxk27zwlk?t=2440
    benchmark::DoNotOptimize(c = a + b);
    benchmark::ClobberMemory();
}

static void BM_SomeFunction(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    SomeFunction();
  }
}
// Register the function as a benchmark
BENCHMARK(BM_SomeFunction);
// Run the benchmark
BENCHMARK_MAIN();