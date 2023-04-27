#ifndef _TYPE_ERASURE_DEV_EXT_H_
#define _TYPE_ERASURE_DEV_EXT_H_

#include "dev_base.h"
#include "types.h"

#include <memory>
#include <vector>

namespace TypeErasureUp {

void statPorts(std::vector<Readable> const&) noexcept;

void writePorts(std::vector<Readable>&, BufferData const&) noexcept;

} // namespace TypeErasureUp

#endif