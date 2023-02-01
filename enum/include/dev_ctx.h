#ifndef _DEV_EXT_H_
#define _DEV_EXT_H_

#include "dev_base.h"
#include "types.h"

#include <memory>
#include <vector>

namespace Enum {

void statPorts(std::vector<std::unique_ptr<Port> > const&) noexcept;

void statPort(std::unique_ptr<Port> const&) noexcept;

void writePorts(std::vector<std::unique_ptr<Port> >&,
                BufferData const&) noexcept;

void writePort(std::unique_ptr<Port>&, BufferData const&) noexcept;

} // namespace Enum

#endif