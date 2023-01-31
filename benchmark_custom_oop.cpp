#include "bench.h"

#include <cstdint>
#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    uint32_t roundCount = (1 < argc) ? atoi(argv[1]) : 2500000;

    using namespace std;
    ostream& out = cout;

    vector<uint32_t> vr = setup();
    doNotOptimize(vr.data());
    vector<TimeDur> vtd;

    using OopPorts = std::vector<std::unique_ptr<Oop::Port> >;

    clock_t c = clock();
    if (clock_t(-1) == c) {
        cerr << "clock fail" << endl;
        exit(1);
    }

    OopPorts oopPorts = OopPortsInitRandom(vr);
    doNotOptimize(oopPorts.data());

    c = clock();
    for (uint32_t i = 0; i < roundCount; ++i) {
        Oop::writePorts(oopPorts, 0xFF);
        clobber();
    }
    vtd.push_back(TimeDur{"Oop updates", clock() - c});

    for (auto& it : vtd) {
        out << it.GetDesc() << ": " << it.GetDur() << endl;
    }

    return 0;
}