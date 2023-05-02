#ifndef _COMMON_BENCH_H_
#define _COMMON_BENCH_H_

void doNotOptimize(void* p);
void clobber();

#include <ctime>

class TimeDur final {
public:
    TimeDur(const char* desc, clock_t tdur);
    TimeDur();

    const char* GetDesc() const noexcept;
    clock_t GetDur() const noexcept;

private:
    const char* desc_;
    clock_t tdur_;
};

#include "enum_type/include/dev_ctx.h_"
#include "enum_type/include/dev_factory.h_"
#include "oop/include/dev_ctx.h_"
#include "oop/include/dev_factory.h_"
#include "strategy/include/dev_ctx.h_"
#include "strategy/include/dev_factory.h_"
#include "type_erasure_up/include/dev_ctx.h_"
#include "type_erasure_up/include/dev_factory.h_"
#include "variant_t/include/dev_ctx.h_"
#include "variant_t/include/dev_factory.h_"
#include "visitor/include/dev_ctx.h_"
#include "visitor/include/dev_factory.h_"

#include <cstdint>
#include <memory>
#include <vector>

/**
 * Generate random static vector of indices
 */
std::vector<uint32_t> setup();

std::vector<std::unique_ptr<Enum::Port> >
EnumPortsInitRandom(std::vector<uint32_t>& v);

std::vector<std::unique_ptr<oop::Port> >
OopPortsInitRandom(std::vector<uint32_t>& v);

std::vector<std::unique_ptr<visitor::Port> >
VisitPortsInitRandom(std::vector<uint32_t>& v);

std::vector<std::unique_ptr<strategy::Port> >
StrategyPortsInitRandom(std::vector<uint32_t>& v);

std::vector<variant_t::Port> VarianttPortsInitRandom(std::vector<uint32_t>& v);

std::vector<type_erasure_up::Readable>
TypeErasureUpPortsInitRandom(std::vector<uint32_t>& v);

#endif