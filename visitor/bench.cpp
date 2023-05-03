#include "common/include/lib.h"
#include "lib.h"
#include <benchmark/benchmark.h>
#include <chrono>

using namespace visitor;
using namespace std;
using namespace common;

// GEN_PROTO_BEGIN
static void BM_A1_VisitorTcpPortStack(benchmark::State& state);
static void BM_A2_VisitorTcpPortHeap(benchmark::State& state);
static void BM_A3_VisitorTcpPortHeapCtorManual(benchmark::State& state);
static void BM_A4_VisitorTcpPortHeapDtorManual(benchmark::State& state);
static void BM_A5_VisitorUpTcpPortHeap(benchmark::State& state);
static void BM_A6_VisitorCreateTcpPortUpFn(benchmark::State& state);
static void BM_A8_VisitorCreateTcpPortUpFnCtorManual(benchmark::State& state);
static void BM_A9_VisitorCreateTcpPortUpFnDtorManual(benchmark::State& state);
static void BM_B0_VisitorCreateTcpPortUpFnDtorManual(benchmark::State& state);
static void BM_Y1_VisitorTcpPortStackCall(benchmark::State& state);
static void BM_Y2_VisitorTcpPortHeapCall(benchmark::State& state);
static void BM_Y3_VisitorVectorGlobalItUpFnCall(benchmark::State& state);
// GEN_PROTO_END

static void BM_A1_VisitorTcpPortStack(benchmark::State& state) {
    for (auto _ : state) {
        TcpPort p = TcpPort("localhost", 2404);
        benchmark::DoNotOptimize(p);
    }
}

static void BM_A2_VisitorTcpPortHeap(benchmark::State& state) {
    for (auto _ : state) {
        Port* p = new TcpPort("localhost", 2404);
        benchmark::DoNotOptimize(p);
        delete p;
    }
}

static void BM_A3_VisitorTcpPortHeapCtorManual(benchmark::State& state) {
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

static void BM_A4_VisitorTcpPortHeapDtorManual(benchmark::State& state) {
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

static void BM_A5_VisitorUpTcpPortHeap(benchmark::State& state) {
    for (auto _ : state) {
        auto p = unique_ptr<Port>(new TcpPort("localhost", 2404));
        benchmark::DoNotOptimize(p);
    }
}

static void BM_A6_VisitorCreateTcpPortUpFn(benchmark::State& state) {
    for (auto _ : state) {
        auto p = createTcpPort("localhost", 2404);
        benchmark::DoNotOptimize(p);
    }
}

static void BM_A8_VisitorCreateTcpPortUpFnCtorManual(benchmark::State& state) {
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

static void BM_A9_VisitorCreateTcpPortUpFnDtorManual(benchmark::State& state) {
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

static void BM_B0_VisitorCreateTcpPortUpFnDtorManual(benchmark::State& state) {
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

static void BM_Y1_VisitorTcpPortStackCall(benchmark::State& state) {
    TcpPort p = TcpPort("localhost", 2404);
    for (auto _ : state) {
        p.accept(Write{BufferData{0x0B}});
    }
    benchmark::DoNotOptimize(p);
}

static void BM_Y2_VisitorTcpPortHeapCall(benchmark::State& state) {
    Port* p = new TcpPort{"localhost", 2404};
    for (auto _ : state) {
        p->accept(Write{BufferData{0x0C}});
    }
    benchmark::DoNotOptimize(p);
}

static void BM_Y3_VisitorVectorGlobalItUpFnCall(benchmark::State& state) {
    auto intVec = GetGlobalRandIntVec();
    auto v = VisitPortsInitRandom(intVec);
    for (auto _ : state) {
        auto p = v[GetNextGlobalIndex()].get();
        p->accept(Write{BufferData{0x0D}});
        benchmark::DoNotOptimize(p);
    }
}

// GEN_BENCHMARK_BEGIN
BENCHMARK(BM_A1_VisitorTcpPortStack);
BENCHMARK(BM_A2_VisitorTcpPortHeap);
BENCHMARK(BM_A3_VisitorTcpPortHeapCtorManual)->UseManualTime();
BENCHMARK(BM_A4_VisitorTcpPortHeapDtorManual)->UseManualTime();
BENCHMARK(BM_A5_VisitorUpTcpPortHeap);
BENCHMARK(BM_A6_VisitorCreateTcpPortUpFn);
BENCHMARK(BM_A8_VisitorCreateTcpPortUpFnCtorManual)->UseManualTime();
BENCHMARK(BM_A9_VisitorCreateTcpPortUpFnDtorManual)->UseManualTime();
BENCHMARK(BM_B0_VisitorCreateTcpPortUpFnDtorManual)->UseManualTime();
BENCHMARK(BM_Y1_VisitorTcpPortStackCall);
BENCHMARK(BM_Y2_VisitorTcpPortHeapCall);
BENCHMARK(BM_Y3_VisitorVectorGlobalItUpFnCall);
// GEN_BENCHMARK_END

// Run the benchmark
BENCHMARK_MAIN();
