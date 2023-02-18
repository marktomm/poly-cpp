#include <benchmark/benchmark.h>

#include "common.h"

constexpr static uint32_t roundCount = 1;

static void BM_EnumRandom(benchmark::State& state)
{
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

static void BM_OopRandom(benchmark::State& state)
{
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

static void BM_VisitorRandom(benchmark::State& state)
{
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

static void BM_StrategyRandom(benchmark::State& state)
{
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

static void BM_VariantRandom(benchmark::State& state)
{
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

static void BM_TypeErasureRandom(benchmark::State& state)
{
    // Perform setup here
    using namespace TypeErasureUp;
    using Ports = std::vector<statable>;
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
BENCHMARK(BM_EnumRandom);
BENCHMARK(BM_OopRandom);
BENCHMARK(BM_VisitorRandom);
BENCHMARK(BM_StrategyRandom);
BENCHMARK(BM_VariantRandom);
BENCHMARK(BM_TypeErasureRandom);
// Run the benchmark
BENCHMARK_MAIN();