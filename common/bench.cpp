#include "bench.h"

#include "enum/dev_ctx.h"
#include "enum/dev_factory.h"
#include "oop/dev_ctx.h"
#include "oop/dev_factory.h"
#include "visitor/dev_ctx.h"
#include "visitor/dev_factory.h"

#include <algorithm>
#include <random>

std::vector<uint32_t> setup()
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

std::vector<std::unique_ptr<Enum::Port> >
EnumPortsInitRandom(std::vector<uint32_t>& v)
{
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

std::vector<std::unique_ptr<Oop::Port> >
OopPortsInitRandom(std::vector<uint32_t>& v)
{
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

std::vector<std::unique_ptr<Visit::Port> >
VisitPortsInitRandom(std::vector<uint32_t>& v)
{
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