#include <benchmark/benchmark.h>

#include "enum/include/dev_ctx.h"
#include "enum/include/dev_factory.h"
#include "oop/include/dev_ctx.h"
#include "oop/include/dev_factory.h"
#include "visitor/include/dev_ctx.h"
#include "visitor/include/dev_factory.h"

#include <algorithm>
#include <cstdint>
#include <random>
#include <vector>

constexpr static uint32_t roundCount = 1;

// static std::vector<std::unique_ptr<Enum::Port> > EnumPortsInit()
// {
//     using namespace Enum;
//     using Ports = std::vector<std::unique_ptr<Port> >;

//     Ports ports;
//     for (uint32_t i = 0; i < 50; ++i) {
//         ports.push_back(CreateTcpPort("localhost", 2404));
//     }
//     for (uint32_t i = 0; i < 50; ++i) {
//         ports.push_back(CreateSerialPort("/dev/ttyUSB0"));
//     }

//     return ports;
// }

// static std::vector<std::unique_ptr<Enum::Port> > EnumPortsInitInterleave()
// {
//     using namespace Enum;
//     using Ports = std::vector<std::unique_ptr<Port> >;

//     Ports ports;
//     for (uint32_t i = 0; i < 50; ++i) {
//         ports.push_back(CreateTcpPort("localhost", 2404));
//         ports.push_back(CreateSerialPort("/dev/ttyUSB0"));
//     }

//     return ports;
// }

// this function guarantees same randomness for all benchmark cases
static std::vector<uint32_t> setup()
{
    static bool setupDone = false;
    static std::vector<uint32_t> v(100);
    if (setupDone) {
        return v;
    }
    std::random_device rd;
    std::mt19937 generator(rd());
    std::generate(v.begin(), v.end(), [n = 0]() mutable { return n++; });
    std::shuffle(v.begin(), v.end(), generator);
    setupDone = true;
    return v;
}

static std::vector<std::unique_ptr<Enum::Port> > EnumPortsInitRandom()
{
    std::vector<uint32_t> v = setup();
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

static std::vector<std::unique_ptr<Oop::Port> > OopPortsInitRandom()
{
    std::vector<uint32_t> v = setup();

    using namespace Oop;
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

static std::vector<std::unique_ptr<Visit::Port> > VisitPortsInitRandom()
{
    std::vector<uint32_t> v = setup();

    using namespace Visit;
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

// static void BM_Enum(benchmark::State& state)
// {
//     // Perform setup here
//     using namespace Enum;
//     using Ports = std::vector<std::unique_ptr<Port> >;
//     Ports ports = EnumPortsInit();
//     for (auto _ : state) {
//         // This code gets timed
//         for (uint32_t i = 0; i < roundCount; ++i)
//             writePorts(ports, 0xFF);
//     }
// }

// static void BM_Enum2(benchmark::State& state)
// {
//     // Perform setup here
//     using namespace Enum;
//     using Ports = std::vector<std::unique_ptr<Port> >;
//     Ports ports = EnumPortsInit();
//     for (auto _ : state) {
//         benchmark::DoNotOptimize(ports.data());
//         // This code gets timed
//         for (uint32_t i = 0; i < roundCount; ++i)
//             writePorts(ports, 0xFF);
//         benchmark::ClobberMemory();
//     }
// }

// static void BM_Enum3(benchmark::State& state)
// {
//     // Perform setup here
//     using namespace Enum;
//     using Ports = std::vector<std::unique_ptr<Port> >;
//     Ports ports = EnumPortsInit();
//     for (auto _ : state) {
//         benchmark::DoNotOptimize(ports.data());
//         // This code gets timed
//         for (uint32_t i = 0; i < roundCount; ++i) {
//             writePorts(ports, 0xFF);
//             benchmark::ClobberMemory();
//         }
//     }
// }

// static void BM_EnumInterleave(benchmark::State& state)
// {
//     // Perform setup here
//     using namespace Enum;
//     using Ports = std::vector<std::unique_ptr<Port> >;
//     Ports ports = EnumPortsInitInterleave();
//     for (auto _ : state) {
//         // This code gets timed
//         for (uint32_t i = 0; i < roundCount; ++i)
//             writePorts(ports, 0xFF);
//     }
// }

// static void BM_EnumInterleave2(benchmark::State& state)
// {
//     // Perform setup here
//     using namespace Enum;
//     using Ports = std::vector<std::unique_ptr<Port> >;
//     Ports ports = EnumPortsInitInterleave();
//     for (auto _ : state) {
//         // This code gets timed
//         benchmark::DoNotOptimize(ports.data());
//         for (uint32_t i = 0; i < roundCount; ++i) {
//             writePorts(ports, 0xFF);
//             benchmark::ClobberMemory();
//         }
//     }
// }

static void BM_Setup(benchmark::State& state)
{
    for (auto _ : state) {
        std::vector<uint32_t> v = setup();
        benchmark::DoNotOptimize(v.data());
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

static void BM_OopRandom(benchmark::State& state)
{
    // Perform setup here
    using namespace Oop;
    using Ports = std::vector<std::unique_ptr<Port> >;
    Ports ports = OopPortsInitRandom();
    for (auto _ : state) {
        // This code gets timed
        benchmark::DoNotOptimize(ports.data());
        for (uint32_t i = 0; i < roundCount; ++i) {
            writePorts(ports, 0xFF);
            benchmark::ClobberMemory();
        }
    }
}

static void BM_VisitorRandom(benchmark::State& state)
{
    // Perform setup here
    using namespace Visit;
    using Ports = std::vector<std::unique_ptr<Port> >;
    Ports ports = VisitPortsInitRandom();
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
// BENCHMARK(BM_Enum);
// BENCHMARK(BM_Enum2);
// BENCHMARK(BM_Enum3);
// BENCHMARK(BM_EnumInterleave);
// BENCHMARK(BM_EnumInterleave2);
BENCHMARK(BM_Setup);
BENCHMARK(BM_EnumRandom);
BENCHMARK(BM_OopRandom);
BENCHMARK(BM_VisitorRandom);
// Run the benchmark
BENCHMARK_MAIN();