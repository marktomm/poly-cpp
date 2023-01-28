#include <benchmark/benchmark.h>

#include "enum/dev_ctx.h"
#include "enum/dev_factory.h"

#include <algorithm>
#include <cstdint>
#include <random>
#include <vector>

constexpr static uint32_t roundCount = 1;

static std::vector<std::unique_ptr<Enum::Port> > EnumPortsInit()
{
    using namespace Enum;
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

static std::vector<std::unique_ptr<Enum::Port> > EnumPortsInitInterleave()
{
    using namespace Enum;
    using Ports = std::vector<std::unique_ptr<Port> >;

    Ports ports;
    for (uint32_t i = 0; i < 50; ++i) {
        ports.push_back(CreateTcpPort("localhost", 2404));
        ports.push_back(CreateSerialPort("/dev/ttyUSB0"));
    }

    return ports;
}

static std::vector<std::unique_ptr<Enum::Port> > EnumPortsInitRandom()
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::vector<uint32_t> v(100);
    std::generate(v.begin(), v.end(), [n = 0]() mutable { return n++; });
    std::shuffle(v.begin(), v.end(), generator);

    using namespace Enum;
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

static void BM_Enum(benchmark::State& state)
{
    // Perform setup here
    using namespace Enum;
    using Ports = std::vector<std::unique_ptr<Port> >;
    Ports ports = EnumPortsInit();
    for (auto _ : state) {
        // This code gets timed
        for (uint32_t i = 0; i < roundCount; ++i)
            writePorts(ports, 0xFF);
    }
}

static void BM_Enum2(benchmark::State& state)
{
    // Perform setup here
    using namespace Enum;
    using Ports = std::vector<std::unique_ptr<Port> >;
    Ports ports = EnumPortsInit();
    for (auto _ : state) {
        benchmark::DoNotOptimize(ports.data());
        // This code gets timed
        for (uint32_t i = 0; i < roundCount; ++i)
            writePorts(ports, 0xFF);
        benchmark::ClobberMemory();
    }
}

static void BM_Enum3(benchmark::State& state)
{
    // Perform setup here
    using namespace Enum;
    using Ports = std::vector<std::unique_ptr<Port> >;
    Ports ports = EnumPortsInit();
    for (auto _ : state) {
        benchmark::DoNotOptimize(ports.data());
        // This code gets timed
        for (uint32_t i = 0; i < roundCount; ++i) {
            writePorts(ports, 0xFF);
            benchmark::ClobberMemory();
        }
    }
}

static void BM_EnumInterleave(benchmark::State& state)
{
    // Perform setup here
    using namespace Enum;
    using Ports = std::vector<std::unique_ptr<Port> >;
    Ports ports = EnumPortsInitInterleave();
    for (auto _ : state) {
        // This code gets timed
        for (uint32_t i = 0; i < roundCount; ++i)
            writePorts(ports, 0xFF);
    }
}

static void BM_EnumInterleave2(benchmark::State& state)
{
    // Perform setup here
    using namespace Enum;
    using Ports = std::vector<std::unique_ptr<Port> >;
    Ports ports = EnumPortsInitInterleave();
    for (auto _ : state) {
        // This code gets timed
        benchmark::DoNotOptimize(ports.data());
        for (uint32_t i = 0; i < roundCount; ++i) {
            writePorts(ports, 0xFF);
            benchmark::ClobberMemory();
        }
    }
}

static void BM_EnumRandom(benchmark::State& state)
{
    // Perform setup here
    using namespace Enum;
    using Ports = std::vector<std::unique_ptr<Port> >;
    Ports ports = EnumPortsInitRandom();
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
BENCHMARK(BM_Enum);
BENCHMARK(BM_Enum2);
BENCHMARK(BM_Enum3);
BENCHMARK(BM_EnumInterleave);
BENCHMARK(BM_EnumInterleave2);
BENCHMARK(BM_EnumRandom);
// Run the benchmark
BENCHMARK_MAIN();