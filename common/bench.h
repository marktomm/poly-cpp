#ifndef _COMMON_BENCH_H_
#define _COMMON_BENCH_H_

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