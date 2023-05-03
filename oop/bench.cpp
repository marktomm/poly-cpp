#include "lib.h"
#include <benchmark/benchmark.h>

using namespace oop;
using namespace std;

// GEN_PROTO_BEGIN
static void BM_A1_OopTcpPortStack(benchmark::State& state);
static void BM_A2_OopTcpPortHeap(benchmark::State& state);
static void BM_A3_OopTcpPortHeapCtorManual(benchmark::State& state);
static void BM_A4_OopTcpPortHeapDtorManual(benchmark::State& state);
static void BM_A5_OopUpTcpPortHeap(benchmark::State& state);
static void BM_A6_OopCreateTcpPortUpFn(benchmark::State& state);
static void BM_A8_OopCreateTcpPortUpFnCtorManual(benchmark::State& state);
static void BM_A9_OopCreateTcpPortUpFnDtorManual(benchmark::State& state);
static void BM_B0_OopCreateTcpPortUpFnDtorManual(benchmark::State& state);
static void BM_Y1_OopTcpPortStackCall(benchmark::State& state);
static void BM_Y2_OopTcpPortHeapCall(benchmark::State& state);
static void BM_Y3_OopVectorGlobalItUpFnCall(benchmark::State& state);
// GEN_PROTO_END

#include <chrono>

static void BM_A1_OopTcpPortStack(benchmark::State& state) {
    for (auto _ : state) {
        TcpPort p = TcpPort("localhost", 2404);
        benchmark::DoNotOptimize(p);
    }
}

static void BM_A2_OopTcpPortHeap(benchmark::State& state) {
    for (auto _ : state) {
        Port* p = new TcpPort("localhost", 2404);
        benchmark::DoNotOptimize(p);
        delete p;
    }
}

static void BM_A3_OopTcpPortHeapCtorManual(benchmark::State& state) {
    for (auto _ : state) {

        auto start = chrono::high_resolution_clock::now();
        Port* p = new TcpPort("localhost", 2404);
        auto end = chrono::high_resolution_clock::now();
        auto elapsed =
            chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        state.SetIterationTime(static_cast<double>(elapsed) / 1e9);
        delete p;
        benchmark::DoNotOptimize(p);
    }
}

static void BM_A4_OopTcpPortHeapDtorManual(benchmark::State& state) {
    for (auto _ : state) {
        auto start = chrono::time_point<chrono::high_resolution_clock>{};
        Port* p = nullptr;
        {
            p = new TcpPort("localhost", 2404);
            start = chrono::high_resolution_clock::now();
            delete p;
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed =
            chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        state.SetIterationTime(static_cast<double>(elapsed) / 1e9);

        benchmark::DoNotOptimize(p);
    }
}

static void BM_A5_OopUpTcpPortHeap(benchmark::State& state) {
    for (auto _ : state) {
        auto p = unique_ptr<Port>(new TcpPort("localhost", 2404));
        benchmark::DoNotOptimize(p);
    }
}

static void BM_A6_OopCreateTcpPortUpFn(benchmark::State& state) {
    for (auto _ : state) {
        auto p = createTcpPort("localhost", 2404);
        benchmark::DoNotOptimize(p);
    }
}

static void BM_A8_OopCreateTcpPortUpFnCtorManual(benchmark::State& state) {
    for (auto _ : state) {

        auto start = chrono::high_resolution_clock::now();
        auto p = createTcpPort("localhost", 2404);
        auto end = chrono::high_resolution_clock::now();
        auto elapsed =
            chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        state.SetIterationTime(static_cast<double>(elapsed) / 1e9);
        benchmark::DoNotOptimize(p);
    }
}

static void BM_A9_OopCreateTcpPortUpFnDtorManual(benchmark::State& state) {
    for (auto _ : state) {
        unique_ptr<Port> p;
        auto start = chrono::time_point<chrono::high_resolution_clock>{};
        {
            p = createTcpPort("localhost", 2404);
            start = chrono::high_resolution_clock::now();
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed =
            chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        state.SetIterationTime(static_cast<double>(elapsed) / 1e9);
        benchmark::DoNotOptimize(p);
    }
}

static void BM_B0_OopCreateTcpPortUpFnDtorManual(benchmark::State& state) {
    auto v = GetGlobalRandBoolVec();
    for (auto _ : state) {
        if (v[GetNextGlobalIndex()]) {
        }
        unique_ptr<Port> p;
        auto start = chrono::time_point<chrono::high_resolution_clock>{};
        {
            p = createTcpPort("localhost", 2404);
            start = chrono::high_resolution_clock::now();
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed =
            chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        state.SetIterationTime(static_cast<double>(elapsed) / 1e9);
        benchmark::DoNotOptimize(p);
    }
}

static void BM_Y1_OopTcpPortStackCall(benchmark::State& state) {
    TcpPort p = TcpPort("localhost", 2404);
    for (auto _ : state) {
        p.Write(BufferData{0x0B});
    }
    benchmark::DoNotOptimize(p);
}

static void BM_Y2_OopTcpPortHeapCall(benchmark::State& state) {
    Port* p = new TcpPort{"localhost", 2404};
    for (auto _ : state) {
        p->Write(BufferData{0x0C});
    }
    benchmark::DoNotOptimize(p);
}

static void BM_Y3_OopVectorGlobalItUpFnCall(benchmark::State& state) {
    auto intVec = GetGlobalRandIntVec();
    auto v = OopPortsInitRandom(intVec);
    for (auto _ : state) {
        auto p = v[GetNextGlobalIndex()].get();
        p->Write(BufferData{0x0D});
        benchmark::DoNotOptimize(p);
    }
}

// GEN_BENCHMARK_BEGIN
BENCHMARK(BM_A1_OopTcpPortStack);
BENCHMARK(BM_A2_OopTcpPortHeap);
BENCHMARK(BM_A3_OopTcpPortHeapCtorManual)->UseManualTime();
BENCHMARK(BM_A4_OopTcpPortHeapDtorManual)->UseManualTime();
BENCHMARK(BM_A5_OopUpTcpPortHeap);
BENCHMARK(BM_A6_OopCreateTcpPortUpFn);
BENCHMARK(BM_A8_OopCreateTcpPortUpFnCtorManual)->UseManualTime();
BENCHMARK(BM_A9_OopCreateTcpPortUpFnDtorManual)->UseManualTime();
BENCHMARK(BM_B0_OopCreateTcpPortUpFnDtorManual)->UseManualTime();
BENCHMARK(BM_Y1_OopTcpPortStackCall);
BENCHMARK(BM_Y2_OopTcpPortHeapCall);
BENCHMARK(BM_Y3_OopVectorGlobalItUpFnCall);
// GEN_BENCHMARK_END

// Run the benchmark
BENCHMARK_MAIN();
