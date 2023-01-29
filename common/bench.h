#ifndef _COMMON_BENCH_H_
#define _COMMON_BENCH_H_

void doNotOptimize(void* p);
void clobber();

#include <ctime>

class TimeDur final
{
public:
    TimeDur(const char* desc, clock_t tdur);
    TimeDur();

    const char* GetDesc() const noexcept;
    clock_t GetDur() const noexcept;

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

#include <cstdint>
#include <memory>
#include <vector>

std::vector<uint32_t> setup();

std::vector<std::unique_ptr<Enum::Port> >
EnumPortsInitRandom(std::vector<uint32_t>& v);

std::vector<std::unique_ptr<Oop::Port> >
OopPortsInitRandom(std::vector<uint32_t>& v);

std::vector<std::unique_ptr<Visit::Port> >
VisitPortsInitRandom(std::vector<uint32_t>& v);

#endif