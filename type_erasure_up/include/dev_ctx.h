#ifndef _TYPE_ERASURE_DEV_EXT_H_
#define _TYPE_ERASURE_DEV_EXT_H_

#include "dev_base.h"
#include "types.h"

#include <memory>
#include <vector>

namespace type_erasure_up {

void readPorts(std::vector<Readable> const&, BufferData&) noexcept;

void writePorts(std::vector<Readable>&, BufferData const&) noexcept;

} // namespace type_erasure_up

#endif