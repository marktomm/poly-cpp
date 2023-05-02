#include <benchmark/benchmark.h>
#include "lib.h"

using namespace visitor;

struct SomeType {};

// GEN_PROTO_BEGIN
// GEN_PROTO_END

static void visitor_bench(benchmark::State& state) {
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
BENCHMARK(visitor_bench);


// GEN_BENCHMARK_BEGIN
// GEN_BENCHMARK_END

// Run the benchmark
BENCHMARK_MAIN();
