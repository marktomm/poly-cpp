#include <benchmark/benchmark.h>

#include "common.h"

constexpr static uint32_t roundCount = 1;

static void BM_Enum(benchmark::State& state) {
    // Perform setup here
    using namespace Enum;
    using Ports = std::vector<std::unique_ptr<Port> >;
    auto randomVector = setup();
    Ports ports = EnumPortsInitRandom(randomVector);
    for (auto _ : state) {
        // This code gets timed
        benchmark::DoNotOptimize(ports.data());
        for (uint32_t i = 0; i < roundCount; ++i) {
            writePorts(ports, 0xFF);
            benchmark::ClobberMemory();
        }
    }
}

static void BM_Oop(benchmark::State& state) {
    // Perform setup here
    using namespace Oop;
    using Ports = std::vector<std::unique_ptr<Port> >;
    auto randomVector = setup();
    Ports ports = OopPortsInitRandom(randomVector);
    for (auto _ : state) {
        // This code gets timed
        benchmark::DoNotOptimize(ports.data());
        for (uint32_t i = 0; i < roundCount; ++i) {
            writePorts(ports, 0xFF);
            benchmark::ClobberMemory();
        }
    }
}

static void BM_Visitor(benchmark::State& state) {
    // Perform setup here
    using namespace Visit;
    using Ports = std::vector<std::unique_ptr<Port> >;
    auto randomVector = setup();
    Ports ports = VisitPortsInitRandom(randomVector);
    for (auto _ : state) {
        // This code gets timed
        benchmark::DoNotOptimize(ports.data());
        for (uint32_t i = 0; i < roundCount; ++i) {
            writePorts(ports, 0xFF);
            benchmark::ClobberMemory();
        }
    }
}

static void BM_Strategy(benchmark::State& state) {
    // Perform setup here
    using namespace Strategy;
    using Ports = std::vector<std::unique_ptr<Port> >;
    auto randomVector = setup();
    Ports ports = StrategyPortsInitRandom(randomVector);
    for (auto _ : state) {
        // This code gets timed
        benchmark::DoNotOptimize(ports.data());
        for (uint32_t i = 0; i < roundCount; ++i) {
            writePorts(ports, 0xFF);
            benchmark::ClobberMemory();
        }
    }
}

static void BM_Variant(benchmark::State& state) {
    // Perform setup here
    using namespace VariantT;
    using Ports = std::vector<Port>;
    auto randomVector = setup();
    Ports ports = VarianttPortsInitRandom(randomVector);
    for (auto _ : state) {
        // This code gets timed
        benchmark::DoNotOptimize(ports.data());
        for (uint32_t i = 0; i < roundCount; ++i) {
            writePorts(ports, static_cast<uint32_t>(0xFF));
            benchmark::ClobberMemory();
        }
    }
}

static void BM_TypeErasure(benchmark::State& state) {
    // Perform setup here
    using namespace TypeErasureUp;
    using Ports = std::vector<Readable>;
    auto randomVector = setup();
    Ports ports = TypeErasureUpPortsInitRandom(randomVector);
    for (auto _ : state) {
        // This code gets timed
        benchmark::DoNotOptimize(ports.data());
        for (uint32_t i = 0; i < roundCount; ++i) {
            writePorts(ports, 0xFF);
            benchmark::ClobberMemory();
        }
    }
}

// Register the function as a benchmark
BENCHMARK(BM_Enum);
BENCHMARK(BM_Oop);
BENCHMARK(BM_Visitor);
BENCHMARK(BM_Strategy);
BENCHMARK(BM_Variant);
BENCHMARK(BM_TypeErasure);
// Run the benchmark
BENCHMARK_MAIN();