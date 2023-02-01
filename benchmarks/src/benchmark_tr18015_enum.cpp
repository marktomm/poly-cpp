#include "common.h"

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

    using EnumPorts = std::vector<std::unique_ptr<Enum::Port> >;

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

    for (auto& it : vtd) {
        out << it.GetDesc() << ": " << it.GetDur() << endl;
    }

    return 0;
}