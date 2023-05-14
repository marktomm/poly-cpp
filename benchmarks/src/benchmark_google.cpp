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

static void BM_B1_Enum_Multi(benchmark::State& state) {
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

static void BM_Y0_Enum(benchmark::State& state) {
    using namespace Enum;
    using namespace enum_type;
    auto intVec = GetGlobalRandIntVec();
    auto v = EnumPortsInitRandom(intVec);
    for (auto _ : state) {
        auto p = v[GetNextGlobalIndex()].get();
        writePort(p, BufferData{0xD});
        benchmark::DoNotOptimize(p);
    }
}

static void BM_Y1_Oop(benchmark::State& state) {
    using namespace oop;
    auto intVec = GetGlobalRandIntVec();
    auto v = OopPortsInitRandom(intVec);
    for (auto _ : state) {
        auto p = v[GetNextGlobalIndex()].get();
        p->Write(BufferData{0x0D});
        benchmark::DoNotOptimize(p);
    }
}

static void BM_Y2_Strategy(benchmark::State& state) {
    using namespace strategy;
    auto intVec = GetGlobalRandIntVec();
    auto v = StrategyPortsInitRandom(intVec);
    for (auto _ : state) {
        auto p = v[GetNextGlobalIndex()].get();
        p->Write(BufferData{0x0D});
        benchmark::DoNotOptimize(p);
    }
}

static void BM_Y3_Visitor(benchmark::State& state) {
    using namespace visitor;
    auto intVec = GetGlobalRandIntVec();
    auto v = VisitPortsInitRandom(intVec);
    for (auto _ : state) {
        auto p = v[GetNextGlobalIndex()].get();
        p->accept(Write{BufferData{0x0D}});
        benchmark::DoNotOptimize(p);
    }
}

static void BM_Y4_Variantt(benchmark::State& state) {
    using namespace variant_t;
    auto intVec = GetGlobalRandIntVec();
    auto v = VarianttPortsInitRandom(intVec);
    for (auto _ : state) {
        auto p = v[GetNextGlobalIndex()];
        visit(Write{}, p, WriteData{static_cast<uint32_t>(0x0D)});
        benchmark::DoNotOptimize(p);
    }
}

static void BM_Y5_TypeErUp(benchmark::State& state) {
    using namespace type_erasure_up;
    auto intVec = GetGlobalRandIntVec();
    auto v = TypeErasureUpPortsInitRandom(intVec);
    for (auto _ : state) {
        auto p = v[GetNextGlobalIndex()];
        write(p, BufferData{0x0D});
        benchmark::DoNotOptimize(p);
    }
}

// Register the function as a benchmark
BENCHMARK(BM_B1_Enum_Multi);
BENCHMARK(BM_B2_Oop);
BENCHMARK(BM_B3_Visitor);
BENCHMARK(BM_B4_Strategy);
BENCHMARK(BM_B5_Variant);
BENCHMARK(BM_B6_TypeErasure);
BENCHMARK(BM_Y0_Enum);
BENCHMARK(BM_Y1_Oop);
BENCHMARK(BM_Y2_Strategy);
BENCHMARK(BM_Y3_Visitor);
BENCHMARK(BM_Y4_Variantt);
BENCHMARK(BM_Y5_TypeErUp);
// Run the benchmark
BENCHMARK_MAIN();