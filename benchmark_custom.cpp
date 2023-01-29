static void doNotOptimize(void* p) { asm volatile("" : : "g"(p) : "memory"); }

static void clobber() { asm volatile("" : : : "memory"); }

#include <ctime>

class TimeDur final
{
public:
    TimeDur(const char* desc, clock_t tdur) : desc_{desc}, tdur_{tdur} {}
    TimeDur() : desc_{0}, tdur_{0} {}

    const char* GetDesc() const noexcept { return desc_; }
    clock_t GetDur() const noexcept { return tdur_; }

private:
    const char* desc_;
    clock_t tdur_;
};

#include "enum/dev_ctx.h"
#include "enum/dev_factory.h"
#include "oop/dev_ctx.h"
#include "oop/dev_factory.h"
#include "visitor/dev_ctx.h"
#include "visitor/dev_factory.h"

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

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

static std::vector<std::unique_ptr<Enum::Port> >
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

static std::vector<std::unique_ptr<Oop::Port> >
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

static std::vector<std::unique_ptr<Visit::Port> >
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

int main(int argc, char** argv)
{
    uint32_t roundCount = (1 < argc) ? atoi(argv[1]) : 2500000;

    using namespace std;
    ostream& out = cout;

    vector<uint32_t> vr = setup();
    doNotOptimize(vr.data());
    vector<TimeDur> vtd;

    using EnumPorts = std::vector<std::unique_ptr<Enum::Port> >;
    using OopPorts = std::vector<std::unique_ptr<Oop::Port> >;
    using VisitPorts = std::vector<std::unique_ptr<Visit::Port> >;

    clock_t c = clock();
    if (clock_t(-1) == c) {
        cerr << "clock fail" << endl;
        exit(1);
    }

    EnumPorts enumPorts = EnumPortsInitRandom(vr);
    doNotOptimize(enumPorts.data());

    c = clock();
    for (uint32_t i = 0; i < roundCount; ++i) {
        Enum::writePorts(enumPorts, 0xFF);
        clobber();
    }
    vtd.push_back(TimeDur{"Enum updates", clock() - c});

    OopPorts oopPorts = OopPortsInitRandom(vr);
    doNotOptimize(oopPorts.data());

    c = clock();
    for (uint32_t i = 0; i < roundCount; ++i) {
        Oop::writePorts(oopPorts, 0xFF);
        clobber();
    }
    vtd.push_back(TimeDur{"Oop updates", clock() - c});

    VisitPorts visitPorts = VisitPortsInitRandom(vr);
    doNotOptimize(visitPorts.data());

    c = clock();
    for (uint32_t i = 0; i < roundCount; ++i) {
        Visit::writePorts(visitPorts, 0xFF);
        clobber();
    }
    vtd.push_back(TimeDur{"Visit updates", clock() - c});

    for (auto& it : vtd) {
        out << it.GetDesc() << ": " << it.GetDur() << endl;
    }

    return 0;
}