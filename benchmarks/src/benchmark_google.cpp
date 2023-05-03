#include <benchmark/benchmark.h>

#include "common/include/lib.h"

#include "enum_type/include/lib.h"
#include "oop/include/lib.h"
#include "strategy/include/lib.h"
#include "type_erasure_up/include/lib.h"
#include "variant_t/include/lib.h"
#include "visitor/include/lib.h"

using namespace common;

constexpr static uint32_t roundCount = 1;

static void BM_B1_Enum(benchmark::State& state) {
    // Perform setup here
    using namespace Enum;
    using namespace enum_type;
    using Ports = std::vector<std::unique_ptr<Port> >;
    auto randomVector = GetGlobalRandIntVec();
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

static void BM_B2_Oop(benchmark::State& state) {
    // Perform setup here
    using namespace oop;
    using Ports = std::vector<std::unique_ptr<Port> >;
    auto randomVector = GetGlobalRandIntVec();
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

static void BM_B3_Visitor(benchmark::State& state) {
    // Perform setup here
    using namespace visitor;
    using Ports = std::vector<std::unique_ptr<Port> >;
    auto randomVector = GetGlobalRandIntVec();
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

static void BM_B4_Strategy(benchmark::State& state) {
    // Perform setup here
    using namespace strategy;
    using Ports = std::vector<std::unique_ptr<Port> >;
    auto randomVector = GetGlobalRandIntVec();
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

static void BM_B5_Variant(benchmark::State& state) {
    // Perform setup here
    using namespace variant_t;
    using Ports = std::vector<Port>;
    auto randomVector = GetGlobalRandIntVec();
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

static void BM_B6_TypeErasure(benchmark::State& state) {
    // Perform setup here
    using namespace type_erasure_up;
    using Ports = std::vector<Readable>;
    auto randomVector = GetGlobalRandIntVec();
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
BENCHMARK(BM_B1_Enum);
BENCHMARK(BM_B2_Oop);
BENCHMARK(BM_B3_Visitor);
BENCHMARK(BM_B4_Strategy);
BENCHMARK(BM_B5_Variant);
BENCHMARK(BM_B6_TypeErasure);
// Run the benchmark
BENCHMARK_MAIN();