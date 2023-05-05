#include "common/include/lib.h"
#include "lib.h"
#include <benchmark/benchmark.h>
#include <chrono>

using namespace strategy;
using namespace std;
using namespace common;

// GEN_PROTO_BEGIN
static void BM_A1_StrategyTcpPortStack(benchmark::State& state);
static void BM_A2_StrategyTcpPortHeap(benchmark::State& state);
static void BM_A3_StrategyTcpPortHeapCtorManual(benchmark::State& state);
static void BM_A4_StrategyTcpPortHeapDtorManual(benchmark::State& state);
static void BM_A5_StrategyUpTcpPortHeap(benchmark::State& state);
static void BM_A6_StrategyCreateTcpPortUpFn(benchmark::State& state);
static void BM_A8_StrategyCreateTcpPortUpFnCtorManual(benchmark::State& state);
static void BM_A9_StrategyCreateTcpPortUpFnDtorManual(benchmark::State& state);
static void BM_B0_StrategyCreateTcpPortUpFnDtorManual(benchmark::State& state);
static void BM_Y1_StrategyTcpPortStackCall(benchmark::State& state);
static void BM_Y2_StrategyTcpPortHeapCall(benchmark::State& state);
static void BM_Y3_StrategyVectorGlobalItUpFnCall(benchmark::State& state);
// GEN_PROTO_END

static void BM_A1_StrategyTcpPortStack(benchmark::State& state) {
    for (auto _ : state) {
        TcpPort p = TcpPort("localhost", 2404, SyslogReadStrategy{},
                            SyncWriteStrategy{});
        benchmark::DoNotOptimize(p);
    }
}

static void BM_A2_StrategyTcpPortHeap(benchmark::State& state) {
    for (auto _ : state) {
        Port* p = new TcpPort("localhost", 2404, SyslogReadStrategy{},
                              SyncWriteStrategy{});
        benchmark::DoNotOptimize(p);
        delete p;
    }
}

static void BM_A3_StrategyTcpPortHeapCtorManual(benchmark::State& state) {
    for (auto _ : state) {

        auto start = chrono::high_resolution_clock::now();
        Port* p = new TcpPort("localhost", 2404, SyslogReadStrategy{},
                              SyncWriteStrategy{});
        auto end = chrono::high_resolution_clock::now();
        auto elapsed =
            chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        state.SetIterationTime(static_cast<double>(elapsed) / 1e9);
        delete p;
        benchmark::DoNotOptimize(p);
    }
}

static void BM_A4_StrategyTcpPortHeapDtorManual(benchmark::State& state) {
    for (auto _ : state) {
        auto start = chrono::time_point<chrono::high_resolution_clock>{};
        Port* p = nullptr;
        {
            p = new TcpPort("localhost", 2404, SyslogReadStrategy{},
                            SyncWriteStrategy{});
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

static void BM_A5_StrategyUpTcpPortHeap(benchmark::State& state) {
    for (auto _ : state) {
        auto p = unique_ptr<Port>(new TcpPort(
            "localhost", 2404, SyslogReadStrategy{}, SyncWriteStrategy{}));
        benchmark::DoNotOptimize(p);
    }
}

static void BM_A6_StrategyCreateTcpPortUpFn(benchmark::State& state) {
    for (auto _ : state) {
        auto p = createTcpPort("localhost", 2404, SyslogReadStrategy{},
                               SyncWriteStrategy{});
        benchmark::DoNotOptimize(p);
    }
}

static void BM_A8_StrategyCreateTcpPortUpFnCtorManual(benchmark::State& state) {
    for (auto _ : state) {

        auto start = chrono::high_resolution_clock::now();
        auto p = createTcpPort("localhost", 2404, SyslogReadStrategy{},
                               SyncWriteStrategy{});
        auto end = chrono::high_resolution_clock::now();
        auto elapsed =
            chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        state.SetIterationTime(static_cast<double>(elapsed) / 1e9);
        benchmark::DoNotOptimize(p);
    }
}

static void BM_A9_StrategyCreateTcpPortUpFnDtorManual(benchmark::State& state) {
    for (auto _ : state) {
        unique_ptr<Port> p;
        auto start = chrono::time_point<chrono::high_resolution_clock>{};
        {
            p = createTcpPort("localhost", 2404, SyslogReadStrategy{},
                              SyncWriteStrategy{});
            start = chrono::high_resolution_clock::now();
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed =
            chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        state.SetIterationTime(static_cast<double>(elapsed) / 1e9);
        benchmark::DoNotOptimize(p);
    }
}

static void BM_B0_StrategyCreateTcpPortUpFnDtorManual(benchmark::State& state) {
    auto v = GetGlobalRandBoolVec();
    for (auto _ : state) {
        if (v[GetNextGlobalIndex()]) {
        }
        unique_ptr<Port> p;
        auto start = chrono::time_point<chrono::high_resolution_clock>{};
        {
            p = createTcpPort("localhost", 2404, SyslogReadStrategy{},
                              SyncWriteStrategy{});
            start = chrono::high_resolution_clock::now();
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed =
            chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        state.SetIterationTime(static_cast<double>(elapsed) / 1e9);
        benchmark::DoNotOptimize(p);
    }
}

static void BM_Y1_StrategyTcpPortStackCall(benchmark::State& state) {
    TcpPort p =
        TcpPort("localhost", 2404, SyslogReadStrategy{}, SyncWriteStrategy{});
    for (auto _ : state) {
        p.Write(BufferData{0x0B});
    }
    benchmark::DoNotOptimize(p);
}

static void BM_Y2_StrategyTcpPortHeapCall(benchmark::State& state) {
    Port* p = new TcpPort{"localhost", 2404, SyslogReadStrategy{},
                          SyncWriteStrategy{}};
    for (auto _ : state) {
        p->Write(BufferData{0x0C});
    }
    benchmark::DoNotOptimize(p);
}

static void BM_Y3_StrategyVectorGlobalItUpFnCall(benchmark::State& state) {
    auto intVec = GetGlobalRandIntVec();
    auto v = StrategyPortsInitRandom(intVec);
    for (auto _ : state) {
        auto p = v[GetNextGlobalIndex()].get();
        p->Write(BufferData{0x0D});
        benchmark::DoNotOptimize(p);
    }
}

// GEN_BENCHMARK_BEGIN
BENCHMARK(BM_A1_StrategyTcpPortStack);
BENCHMARK(BM_A2_StrategyTcpPortHeap);
BENCHMARK(BM_A3_StrategyTcpPortHeapCtorManual)->UseManualTime();
BENCHMARK(BM_A4_StrategyTcpPortHeapDtorManual)->UseManualTime();
BENCHMARK(BM_A5_StrategyUpTcpPortHeap);
BENCHMARK(BM_A6_StrategyCreateTcpPortUpFn);
BENCHMARK(BM_A8_StrategyCreateTcpPortUpFnCtorManual)->UseManualTime();
BENCHMARK(BM_A9_StrategyCreateTcpPortUpFnDtorManual)->UseManualTime();
BENCHMARK(BM_B0_StrategyCreateTcpPortUpFnDtorManual)->UseManualTime();
BENCHMARK(BM_Y1_StrategyTcpPortStackCall);
BENCHMARK(BM_Y2_StrategyTcpPortHeapCall);
BENCHMARK(BM_Y3_StrategyVectorGlobalItUpFnCall);
// GEN_BENCHMARK_END

// Run the benchmark
BENCHMARK_MAIN();
