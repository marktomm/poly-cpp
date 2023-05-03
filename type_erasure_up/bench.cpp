#include "common/include/lib.h"
#include "lib.h"
#include <benchmark/benchmark.h>
#include <chrono>

using namespace type_erasure_up;
using namespace std;
using namespace common;

// GEN_PROTO_BEGIN
static void BM_A1_TypeErUpTcpPortStack(benchmark::State& state);
static void BM_Y1_TypeErUpTcpPortStackCall(benchmark::State& state);
static void BM_Y3_TypeErUpVectorGlobalItUpFnCall(benchmark::State& state);
// GEN_PROTO_END

static void BM_A1_TypeErUpTcpPortStack(benchmark::State& state) {
    for (auto _ : state) {
        TcpPort p = TcpPort("localhost", 2404);
        benchmark::DoNotOptimize(p);
    }
}

// static void BM_A2_TypeErUpTcpPortHeap(benchmark::State& state) {
//     for (auto _ : state) {
//         Port* p = new TcpPort("localhost", 2404);
//         benchmark::DoNotOptimize(p);
//         delete p;
//     }
// }

// static void BM_A3_TypeErUpTcpPortHeapCtorManual(benchmark::State& state) {
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

// static void BM_A4_TypeErUpTcpPortHeapDtorManual(benchmark::State& state) {
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

// static void BM_A5_TypeErUpUpTcpPortHeap(benchmark::State& state) {
//     for (auto _ : state) {
//         auto p = unique_ptr<Port>(new TcpPort("localhost", 2404));
//         benchmark::DoNotOptimize(p);
//     }
// }

// static void BM_A6_TypeErUpCreateTcpPortUpFn(benchmark::State& state) {
//     for (auto _ : state) {
//         auto p = createTcpPort("localhost", 2404);
//         benchmark::DoNotOptimize(p);
//     }
// }

// static void BM_A8_TypeErUpCreateTcpPortUpFnCtorManual(benchmark::State&
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

// static void BM_A9_TypeErUpCreateTcpPortUpFnDtorManual(benchmark::State&
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

// static void BM_B0_TypeErUpCreateTcpPortUpFnDtorManual(benchmark::State&
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

static void BM_Y1_TypeErUpTcpPortStackCall(benchmark::State& state) {
    TcpPort p = TcpPort("localhost", 2404);
    for (auto _ : state) {
        p.Write(BufferData{0x0B});
    }
    benchmark::DoNotOptimize(p);
}

// static void BM_Y2_TypeErUpTcpPortHeapCall(benchmark::State& state) {
//     TcpPort* p = new TcpPort{"localhost", 2404};
//     for (auto _ : state) {
// p.Write(BufferData{0x0B});
//     }
//     benchmark::DoNotOptimize(p);
// }

static void BM_Y3_TypeErUpVectorGlobalItUpFnCall(benchmark::State& state) {
    auto intVec = GetGlobalRandIntVec();
    auto v = TypeErasureUpPortsInitRandom(intVec);
    for (auto _ : state) {
        auto p = v[GetNextGlobalIndex()];
        write(p, BufferData{0x0D});
        benchmark::DoNotOptimize(p);
    }
}

// GEN_BENCHMARK_BEGIN
BENCHMARK(BM_A1_TypeErUpTcpPortStack);
BENCHMARK(BM_Y1_TypeErUpTcpPortStackCall);
BENCHMARK(BM_Y3_TypeErUpVectorGlobalItUpFnCall);
// GEN_BENCHMARK_END

// Run the benchmark
BENCHMARK_MAIN();
