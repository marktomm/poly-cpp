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

#include "enum/include/dev_ctx.h"
#include "enum/include/dev_factory.h"
#include "oop/include/dev_ctx.h"
#include "oop/include/dev_factory.h"
#include "strategy/include/dev_ctx.h"
#include "strategy/include/dev_factory.h"
#include "type_erasure_up/include/dev_ctx.h"
#include "type_erasure_up/include/dev_factory.h"
#include "variant_t/include/dev_ctx.h"
#include "variant_t/include/dev_factory.h"
#include "visitor/include/dev_ctx.h"
#include "visitor/include/dev_factory.h"

#include <cstdint>
#include <memory>
#include <vector>

/**
 * Generate random static vector of indices
 */
std::vector<uint32_t> setup();

std::vector<std::unique_ptr<Enum::Port> >
EnumPortsInitRandom(std::vector<uint32_t>& v);

std::vector<std::unique_ptr<Oop::Port> >
OopPortsInitRandom(std::vector<uint32_t>& v);

std::vector<std::unique_ptr<Visit::Port> >
VisitPortsInitRandom(std::vector<uint32_t>& v);

std::vector<std::unique_ptr<Strategy::Port> >
StrategyPortsInitRandom(std::vector<uint32_t>& v);

std::vector<VariantT::Port> VarianttPortsInitRandom(std::vector<uint32_t>& v);

std::vector<TypeErasureUp::statable>
TypeErasureUpPortsInitRandom(std::vector<uint32_t>& v);

#endif