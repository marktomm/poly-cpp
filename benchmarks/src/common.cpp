#include "common.h"

void doNotOptimize(void* p) { asm volatile("" : : "g"(p) : "memory"); }
void clobber() { asm volatile("" : : : "memory"); }

TimeDur::TimeDur(const char* desc, clock_t tdur) : desc_{desc}, tdur_{tdur} {}
TimeDur::TimeDur() : desc_{0}, tdur_{0} {}

const char* TimeDur::GetDesc() const noexcept { return desc_; }
clock_t TimeDur::GetDur() const noexcept { return tdur_; }

#include <algorithm>
#include <random>

std::vector<uint32_t> setup() {
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
EnumPortsInitRandom(std::vector<uint32_t>& v) {
    using namespace Enum;
    using Ports = std::vector<std::unique_ptr<Port> >;

    Ports ports(100);
    for (uint32_t i = 0; i < 50; ++i) {
        ports[v[i]] = createTcpPort("localhost", 2404);
    }
    for (uint32_t i = 50; i < 100; ++i) {
        ports[v[i]] = createSerialPort("/dev/ttyUSB0");
    }

    return ports;
}

std::vector<std::unique_ptr<oop::Port> >
OopPortsInitRandom(std::vector<uint32_t>& v) {
    using namespace oop;
    using Ports = std::vector<std::unique_ptr<Port> >;

    Ports ports(100);
    for (uint32_t i = 0; i < 50; ++i) {
        ports[v[i]] = createTcpPort("localhost", 2404);
    }
    for (uint32_t i = 50; i < 100; ++i) {
        ports[v[i]] = createSerialPort("/dev/ttyUSB0");
    }

    return ports;
}

std::vector<std::unique_ptr<visitor::Port> >
VisitPortsInitRandom(std::vector<uint32_t>& v) {
    using namespace visitor;
    using Ports = std::vector<std::unique_ptr<Port> >;

    Ports ports(100);
    for (uint32_t i = 0; i < 50; ++i) {
        ports[v[i]] = createTcpPort("localhost", 2404);
    }
    for (uint32_t i = 50; i < 100; ++i) {
        ports[v[i]] = createSerialPort("/dev/ttyUSB0");
    }

    return ports;
}

#include "strategy/include/dev_algo.h"

std::vector<std::unique_ptr<strategy::Port> >
StrategyPortsInitRandom(std::vector<uint32_t>& v) {
    using namespace strategy;
    using Ports = std::vector<std::unique_ptr<Port> >;

    Ports ports(100);
    for (uint32_t i = 0; i < 50; ++i) {
        ports[v[i]] =
            createTcpPort("localhost", 2404, SyslogReadTcpPortStrategy{},
                          SyncWriteTcpPortStrategy{});
    }
    for (uint32_t i = 50; i < 100; ++i) {
        ports[v[i]] =
            createSerialPort("/dev/ttyUSB0", SyslogReadSerialPortStrategy{},
                             SyncWriteSerialPortStrategy{});
    }

    return ports;
}

template<class T>
void rreorder(std::vector<T>& v, std::vector<uint32_t> const& order) {
    for (uint32_t s = 1, d; s < order.size(); ++s) {
        for (d = order[s]; d < s; d = order[d])
            ;
        if (d == s)
            while (d = order[d], d != s)
                swap(v[s], v[d]);
    }
}

std::vector<variant_t::Port> VarianttPortsInitRandom(std::vector<uint32_t>& v) {
    using namespace variant_t;
    using Ports = std::vector<Port>;

    Ports ports;
    for (uint32_t i = 0; i < 50; ++i) {
        ports.push_back(createTcpPort("localhost", 2404));
    }
    for (uint32_t i = 50; i < 100; ++i) {
        ports.push_back(createSerialPort("/dev/ttyUSB0"));
    }

    rreorder(ports, v);

    return ports;
}

std::vector<type_erasure_up::Readable>
TypeErasureUpPortsInitRandom(std::vector<uint32_t>& v) {

    using namespace type_erasure_up;
    using Ports = std::vector<Readable>;

    Ports ports;
    for (uint32_t i = 0; i < 50; ++i) {
        ports.push_back(createTcpPort("localhost", 2404));
    }
    for (uint32_t i = 50; i < 100; ++i) {
        ports.push_back(createSerialPort("/dev/ttyUSB0"));
    }

    rreorder(ports, v);

    return ports;
}
