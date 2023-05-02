#include <benchmark/benchmark.h>
#include "lib.h"

using namespace type_erasure_up;

struct SomeType {};

// GEN_PROTO_BEGIN
// GEN_PROTO_END

static void type_erasure_up_bench(benchmark::State& state) {
    // Perform setup here
    using Ports = std::vector<SomeType>;
    Ports ports;
    // ...
    for (auto _ : state) {
        // This code gets timed
        benchmark::DoNotOptimize(ports.data());
        //...
        benchmark::ClobberMemory();
    }
}

// Register the function as a benchmark
BENCHMARK(type_erasure_up_bench);


// GEN_BENCHMARK_BEGIN
// GEN_BENCHMARK_END

// Run the benchmark
BENCHMARK_MAIN();
