#include <benchmark/benchmark.h>

#include "enum/dev_ctx.h"
#include "enum/dev_factory.h"

#include <algorithm>
#include <cstdint>
#include <random>
#include <vector>

// DoNotOptimize
static void escape(void* p) { asm volatile("" : : "g"(p) : "memory"); }

// ClobberMemory
static void clobber() { asm volatile("" : : : "memory"); }

void SomeFunction()
{
    int a = 1;
    int b = 2;
    int c = 0;

    // https://youtu.be/nXaxk27zwlk?t=2440
    // https://github.com/google/benchmark/blob/v1.7.1/docs/user_guide.md
    benchmark::DoNotOptimize(c = a + b);
    benchmark::ClobberMemory();
}

static std::vector<std::unique_ptr<Port> > EnumPortsInit()
{
    using Ports = std::vector<std::unique_ptr<Port> >;

    Ports ports;
    for (uint32_t i = 0; i < 50; ++i) {
        ports.push_back(CreateTcpPort("localhost", 2404));
    }
    for (uint32_t i = 0; i < 50; ++i) {
        ports.push_back(CreateSerialPort("/dev/ttyUSB0"));
    }

    return ports;
}

static std::vector<std::unique_ptr<Port> > EnumPortsInitInterleave()
{
    using Ports = std::vector<std::unique_ptr<Port> >;

    Ports ports;
    for (uint32_t i = 0; i < 50; ++i) {
        ports.push_back(CreateTcpPort("localhost", 2404));
        ports.push_back(CreateSerialPort("/dev/ttyUSB0"));
    }

    return ports;
}

int f()
{
    static int i;
    return i++;
}

static std::vector<std::unique_ptr<Port> > EnumPortsInitRandom()
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::vector<uint32_t> v(100);
    std::generate(v.begin(), v.end(), [n = 0]() mutable { return n++; });
    std::shuffle(v.begin(), v.end(), generator);

    using Ports = std::vector<std::unique_ptr<Port> >;

    Ports ports(100);
    for (uint32_t i = 0; i < 50; ++i) {
        ports[v[i]] = CreateTcpPort("localhost", 2404);
    }
    for (uint32_t i = 50; i < 100; ++i) {
        ports[v[i]] = CreateSerialPort("/dev/ttyUSB0");
    }

    return ports;
}

static void BM_SomeFunction(benchmark::State& state)
{
    // Perform setup here
    using Ports = std::vector<std::unique_ptr<Port> >;
    Ports ports = EnumPortsInit();
    for (auto _ : state) {
        // This code gets timed
        for (uint32_t i = 0; i < 1000; ++i)
            writePorts(ports, 0xFF);
    }
}

static void BM_SomeFunction2(benchmark::State& state)
{
    // Perform setup here
    using Ports = std::vector<std::unique_ptr<Port> >;
    Ports ports = EnumPortsInitInterleave();
    for (auto _ : state) {
        // This code gets timed
        for (uint32_t i = 0; i < 1000; ++i)
            writePorts(ports, 0xFF);
    }
}

static void BM_SomeFunction3(benchmark::State& state)
{
    // Perform setup here
    using Ports = std::vector<std::unique_ptr<Port> >;
    Ports ports = EnumPortsInit();
    for (auto _ : state) {
        benchmark::DoNotOptimize(ports.data());
        // This code gets timed
        for (uint32_t i = 0; i < 1000; ++i)
            writePorts(ports, 0xFF);
        benchmark::ClobberMemory();
    }
}

static void BM_SomeFunction4(benchmark::State& state)
{
    // Perform setup here
    using Ports = std::vector<std::unique_ptr<Port> >;
    Ports ports = EnumPortsInitInterleave();
    for (auto _ : state) {
        // This code gets timed
        benchmark::DoNotOptimize(ports.data());
        for (uint32_t i = 0; i < 1000; ++i) {
            writePorts(ports, 0xFF);
            benchmark::ClobberMemory();
        }
    }
}

static void BM_SomeFunction5(benchmark::State& state)
{
    // Perform setup here
    using Ports = std::vector<std::unique_ptr<Port> >;
    Ports ports = EnumPortsInitInterleave();

    std::random_device rd;
    std::mt19937 generator(rd());
    std::vector<uint32_t> v(100);
    std::generate(v.begin(), v.end(), [n = 0]() mutable { return n++; });
    std::shuffle(v.begin(), v.end(), generator);

    for (auto _ : state) {
        // This code gets timed
        benchmark::DoNotOptimize(ports.data());
        benchmark::DoNotOptimize(&v);
        for (uint32_t i = 0; i < 1000; ++i) {
            for (auto& it : v) {
                writePort(ports[it], 0xFF);
            }
            // writePorts(ports, 0xFF);
            benchmark::ClobberMemory();
        }
    }
}

static void BM_SomeFunction6(benchmark::State& state)
{
    // Perform setup here
    using Ports = std::vector<std::unique_ptr<Port> >;
    Ports ports = EnumPortsInitRandom();
    for (auto _ : state) {
        // This code gets timed
        benchmark::DoNotOptimize(ports.data());
        for (uint32_t i = 0; i < 1000; ++i) {
            writePorts(ports, 0xFF);
            benchmark::ClobberMemory();
        }
    }
}

// Register the function as a benchmark
BENCHMARK(BM_SomeFunction);
BENCHMARK(BM_SomeFunction2);
BENCHMARK(BM_SomeFunction3);
BENCHMARK(BM_SomeFunction4);
BENCHMARK(BM_SomeFunction5);
BENCHMARK(BM_SomeFunction6);
// Run the benchmark
BENCHMARK_MAIN();