#include "lib.h"
#include <benchmark/benchmark.h>

#include <chrono>

using namespace Enum;
using namespace std;

// GEN_PROTO_BEGIN
static void BM_00_RelativeNoopBase(benchmark::State& state);
static void BM_01_RelativeInt(benchmark::State& state);
static void BM_02_RelativeEmptyFn(benchmark::State& state);
static void BM_03_RelativeEmptyFnInt(benchmark::State& state);
static void BM_04_RelativePauseResume(benchmark::State& state);
static void BM_05_RelativeManual(benchmark::State& state);
static void BM_06_RelativeManualBatch(benchmark::State& state);
static void BM_A1_EnumTcpPortStack(benchmark::State& state);
static void BM_A2_EnumTcpPortHeap(benchmark::State& state);
static void BM_A3_EnumTcpPortHeapCtorManual(benchmark::State& state);
static void BM_A4_EnumTcpPortHeapDtorManual(benchmark::State& state);
static void BM_A5_EnumUpTcpPortHeap(benchmark::State& state);
static void BM_A6_EnumCreateTcpPortUpFn(benchmark::State& state);
static void BM_A8_EnumCreateTcpPortUpFnCtorManual(benchmark::State& state);
static void BM_A9_EnumCreateTcpPortUpFnDtorManual(benchmark::State& state);
static void BM_B1_EnumTcpPortHeapCall(benchmark::State& state);
static void BM_B1_EnumTcpPortStackCall(benchmark::State& state);
// GEN_PROTO_END

void emptyFn(){};

void emptyFnInt() {
    int x = 1;
    benchmark::DoNotOptimize(x);
};

static void BM_00_RelativeNoopBase(benchmark::State& state) {
    for (auto _ : state) {
    }
}

static void BM_01_RelativeInt(benchmark::State& state) {
    for (auto _ : state) {
        int x = 1;
        benchmark::DoNotOptimize(x);
    }
}

static void BM_02_RelativeEmptyFn(benchmark::State& state) {
    for (auto _ : state) {
        emptyFn();
    }
}

static void BM_03_RelativeEmptyFnInt(benchmark::State& state) {
    for (auto _ : state) {
        emptyFnInt();
    }
}

static void BM_04_RelativePauseResume(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        state.ResumeTiming();
    }
}

static void BM_05_RelativeManual(benchmark::State& state) {
    for (auto _ : state) {
        auto start = chrono::high_resolution_clock::now();
        auto end = chrono::high_resolution_clock::now();
        auto elapsed =
            chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        state.SetIterationTime(static_cast<double>(elapsed) / 1e9);
    }
}

static void BM_06_RelativeManualBatch(benchmark::State& state) {
    while (state.KeepRunningBatch(1)) {
        auto start = chrono::high_resolution_clock::now();
        auto end = chrono::high_resolution_clock::now();
        auto elapsed =
            chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        state.SetIterationTime(static_cast<double>(elapsed) / 1e9);
    }
}

static void BM_A1_EnumTcpPortStack(benchmark::State& state) {
    for (auto _ : state) {
        TcpPort p = TcpPort("localhost", 2404);
        benchmark::DoNotOptimize(p);
    }
}

static void BM_A2_EnumTcpPortHeap(benchmark::State& state) {
    for (auto _ : state) {
        Port* p = new TcpPort("localhost", 2404);
        benchmark::DoNotOptimize(p);
        delete p;
    }
}

static void BM_A3_EnumTcpPortHeapCtorManual(benchmark::State& state) {
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

static void BM_A4_EnumTcpPortHeapDtorManual(benchmark::State& state) {
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

static void BM_A5_EnumUpTcpPortHeap(benchmark::State& state) {
    for (auto _ : state) {
        auto p = unique_ptr<Port>(new TcpPort("localhost", 2404));
        benchmark::DoNotOptimize(p);
    }
}

static void BM_A6_EnumCreateTcpPortUpFn(benchmark::State& state) {
    for (auto _ : state) {
        auto p = createTcpPort("localhost", 2404);
        benchmark::DoNotOptimize(p);
    }
}

static void BM_A8_EnumCreateTcpPortUpFnCtorManual(benchmark::State& state) {
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

static void BM_A9_EnumCreateTcpPortUpFnDtorManual(benchmark::State& state) {
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

static void BM_B1_EnumTcpPortStackCall(benchmark::State& state) {
    TcpPort p = TcpPort("localhost", 2404);
    for (auto _ : state) {
        writePort(&p, BufferData{0x0B});
    }
    benchmark::DoNotOptimize(p);
}

static void BM_B1_EnumTcpPortHeapCall(benchmark::State& state) {
    Port* p = new TcpPort{"localhost", 2404};
    for (auto _ : state) {
        writePort(p, BufferData{0x0C});
    }
    benchmark::DoNotOptimize(p);
}

// GEN_BENCHMARK_BEGIN
BENCHMARK(BM_00_RelativeNoopBase);
BENCHMARK(BM_01_RelativeInt);
BENCHMARK(BM_02_RelativeEmptyFn);
BENCHMARK(BM_03_RelativeEmptyFnInt);
BENCHMARK(BM_04_RelativePauseResume);
BENCHMARK(BM_05_RelativeManual)->UseManualTime();
BENCHMARK(BM_06_RelativeManualBatch)->UseManualTime();
BENCHMARK(BM_A1_EnumTcpPortStack);
BENCHMARK(BM_A2_EnumTcpPortHeap);
BENCHMARK(BM_A3_EnumTcpPortHeapCtorManual)->UseManualTime();
BENCHMARK(BM_A4_EnumTcpPortHeapDtorManual)->UseManualTime();
BENCHMARK(BM_A5_EnumUpTcpPortHeap);
BENCHMARK(BM_A6_EnumCreateTcpPortUpFn);
BENCHMARK(BM_A8_EnumCreateTcpPortUpFnCtorManual)->UseManualTime();
BENCHMARK(BM_A9_EnumCreateTcpPortUpFnDtorManual)->UseManualTime();
BENCHMARK(BM_B1_EnumTcpPortHeapCall);
BENCHMARK(BM_B1_EnumTcpPortStackCall);
// GEN_BENCHMARK_END

// Run the benchmark
BENCHMARK_MAIN();
