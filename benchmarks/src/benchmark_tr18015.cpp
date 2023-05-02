#include "common.h"

#include <cstdint>
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
    uint32_t roundCount =
        (1 < argc) ? static_cast<uint32_t>(atoi(argv[1])) : 2500000;

    using namespace std;
    ostream& out = cout;

    vector<uint32_t> vr = setup();
    doNotOptimize(vr.data());
    vector<TimeDur> vtd;

    clock_t c = clock();
    if (clock_t(-1) == c) {
        cerr << "clock fail" << endl;
        exit(1);
    }

    using EnumPorts = std::vector<std::unique_ptr<Enum::Port> >;
    EnumPorts enumPorts = EnumPortsInitRandom(vr);
    doNotOptimize(enumPorts.data());

    c = clock();
    for (uint32_t i = 0; i < roundCount; ++i) {
        Enum::writePorts(enumPorts, 0xFF);
        clobber();
    }
    vtd.push_back(TimeDur{"Enum updates", clock() - c});

    using OopPorts = std::vector<std::unique_ptr<oop::Port> >;
    OopPorts oopPorts = OopPortsInitRandom(vr);
    doNotOptimize(oopPorts.data());

    c = clock();
    for (uint32_t i = 0; i < roundCount; ++i) {
        oop::writePorts(oopPorts, 0xFF);
        clobber();
    }
    vtd.push_back(TimeDur{"Oop updates", clock() - c});

    using VisitPorts = std::vector<std::unique_ptr<visitor::Port> >;
    VisitPorts visitPorts = VisitPortsInitRandom(vr);
    doNotOptimize(visitPorts.data());

    c = clock();
    for (uint32_t i = 0; i < roundCount; ++i) {
        visitor::writePorts(visitPorts, 0xFF);
        clobber();
    }
    vtd.push_back(TimeDur{"Visit updates", clock() - c});

    using StrategyPorts = std::vector<std::unique_ptr<strategy::Port> >;
    StrategyPorts strategyPorts = StrategyPortsInitRandom(vr);
    doNotOptimize(strategyPorts.data());

    c = clock();
    for (uint32_t i = 0; i < roundCount; ++i) {
        strategy::writePorts(strategyPorts, 0xFF);
        clobber();
    }
    vtd.push_back(TimeDur{"Strategy updates", clock() - c});

    using VarianttPorts = std::vector<VariantT::Port>;
    VarianttPorts varianttPorts = VarianttPortsInitRandom(vr);
    doNotOptimize(varianttPorts.data());

    c = clock();
    for (uint32_t i = 0; i < roundCount; ++i) {
        VariantT::writePorts(varianttPorts, static_cast<uint32_t>(0xFF));
        clobber();
    }
    vtd.push_back(TimeDur{"Variantt updates", clock() - c});

    using TypeErasureUpPorts = std::vector<TypeErasureUp::Readable>;
    TypeErasureUpPorts typeErasureUpPorts = TypeErasureUpPortsInitRandom(vr);
    doNotOptimize(typeErasureUpPorts.data());

    c = clock();
    for (uint32_t i = 0; i < roundCount; ++i) {
        TypeErasureUp::writePorts(typeErasureUpPorts, 0xFF);
        clobber();
    }
    vtd.push_back(TimeDur{"TypeErasureUp updates", clock() - c});

    for (auto& it : vtd) {
        out << it.GetDesc() << ": " << it.GetDur() << endl;
    }

    return 0;
}