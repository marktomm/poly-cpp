#include "common/include/lib.h"
#include "lib.h"
#include <benchmark/benchmark.h>
#include <chrono>

using namespace variant_t;
using namespace std;
using namespace common;

// GEN_PROTO_BEGIN
static void BM_A1_VarianttTcpPortStack(benchmark::State& state);
static void BM_Y1_VarianttTcpPortStackCall(benchmark::State& state);
static void BM_Y3_VarianttVectorGlobalItUpFnCall(benchmark::State& state);
// GEN_PROTO_END

static void BM_A1_VarianttTcpPortStack(benchmark::State& state) {
    for (auto _ : state) {
        TcpPort p = TcpPort("localhost", 2404);
        benchmark::DoNotOptimize(p);
    }
}

// static void BM_A2_VarianttTcpPortHeap(benchmark::State& state) {
//     for (auto _ : state) {
//         Port* p = new TcpPort("localhost", 2404);
//         benchmark::DoNotOptimize(p);
//         delete p;
//     }
// }

// static void BM_A3_VarianttTcpPortHeapCtorManual(benchmark::State& state) {
//     for (auto _ : state) {

//         auto start = chrono::high_resolution_clock::now();
//         Port* p = new TcpPort("localhost", 2404);
//         auto end = chrono::high_resolution_clock::now();
//         auto elapsed =
//             chrono::duration_cast<chrono::nanoseconds>(end - start).count();

//         state.SetIterationTime(static_cast<double>(elapsed) / 1e9);
//         delete p;
//         benchmark::DoNotOptimize(p);
//     }
// }

// static void BM_A4_VarianttTcpPortHeapDtorManual(benchmark::State& state) {
//     for (auto _ : state) {
//         auto start = chrono::time_point<chrono::high_resolution_clock>{};
//         Port* p = nullptr;
//         {
//             p = new TcpPort("localhost", 2404);
//             start = chrono::high_resolution_clock::now();
//             delete p;
//         }

//         auto end = chrono::high_resolution_clock::now();
//         auto elapsed =
//             chrono::duration_cast<chrono::nanoseconds>(end - start).count();

//         state.SetIterationTime(static_cast<double>(elapsed) / 1e9);

//         benchmark::DoNotOptimize(p);
//     }
// }

// static void BM_A5_VarianttUpTcpPortHeap(benchmark::State& state) {
//     for (auto _ : state) {
//         auto p = unique_ptr<Port>(new TcpPort("localhost", 2404));
//         benchmark::DoNotOptimize(p);
//     }
// }

// static void BM_A6_VarianttCreateTcpPortUpFn(benchmark::State& state) {
//     for (auto _ : state) {
//         auto p = createTcpPort("localhost", 2404);
//         benchmark::DoNotOptimize(p);
//     }
// }

// static void BM_A8_VarianttCreateTcpPortUpFnCtorManual(benchmark::State&
// state) {
//     for (auto _ : state) {

//         auto start = chrono::high_resolution_clock::now();
//         auto p = createTcpPort("localhost", 2404);
//         auto end = chrono::high_resolution_clock::now();
//         auto elapsed =
//             chrono::duration_cast<chrono::nanoseconds>(end - start).count();

//         state.SetIterationTime(static_cast<double>(elapsed) / 1e9);
//         benchmark::DoNotOptimize(p);
//     }
// }

// static void BM_A9_VarianttCreateTcpPortUpFnDtorManual(benchmark::State&
// state) {
//     for (auto _ : state) {
//         Port p;
//         auto start = chrono::time_point<chrono::high_resolution_clock>{};
//         {
//             p = createTcpPort("localhost", 2404);
//             start = chrono::high_resolution_clock::now();
//         }

//         auto end = chrono::high_resolution_clock::now();
//         auto elapsed =
//             chrono::duration_cast<chrono::nanoseconds>(end - start).count();

//         state.SetIterationTime(static_cast<double>(elapsed) / 1e9);
//         benchmark::DoNotOptimize(p);
//     }
// }

// static void BM_B0_VarianttCreateTcpPortUpFnDtorManual(benchmark::State&
// state) {
//     auto v = GetGlobalRandBoolVec();
//     for (auto _ : state) {
//         if (v[GetNextGlobalIndex()]) {
//         }
//         Port p;
//         auto start = chrono::time_point<chrono::high_resolution_clock>{};
//         {
//             p = createTcpPort("localhost", 2404);
//             start = chrono::high_resolution_clock::now();
//         }

//         auto end = chrono::high_resolution_clock::now();
//         auto elapsed =
//             chrono::duration_cast<chrono::nanoseconds>(end - start).count();

//         state.SetIterationTime(static_cast<double>(elapsed) / 1e9);
//         benchmark::DoNotOptimize(p);
//     }
// }

static void BM_Y1_VarianttTcpPortStackCall(benchmark::State& state) {
    Port p = TcpPort("localhost", 2404);
    for (auto _ : state) {
        visit(Write{}, p, WriteData{static_cast<uint32_t>(0x0B)});
    }
    benchmark::DoNotOptimize(p);
}

// static void BM_Y2_VarianttTcpPortHeapCall(benchmark::State& state) {
//     TcpPort* p = new TcpPort{"localhost", 2404};
//     for (auto _ : state) {
//         visit(Write{}, *p, WriteData{static_cast<uint32_t>(0x0C)});
//     }
//     benchmark::DoNotOptimize(p);
// }

static void BM_Y3_VarianttVectorGlobalItUpFnCall(benchmark::State& state) {
    auto intVec = GetGlobalRandIntVec();
    auto v = VarianttPortsInitRandom(intVec);
    for (auto _ : state) {
        auto p = v[GetNextGlobalIndex()];
        visit(Write{}, p, WriteData{static_cast<uint32_t>(0x0D)});
        benchmark::DoNotOptimize(p);
    }
}

// GEN_BENCHMARK_BEGIN
BENCHMARK(BM_A1_VarianttTcpPortStack);
BENCHMARK(BM_Y1_VarianttTcpPortStackCall);
BENCHMARK(BM_Y3_VarianttVectorGlobalItUpFnCall);
// GEN_BENCHMARK_END

// Run the benchmark
BENCHMARK_MAIN();
