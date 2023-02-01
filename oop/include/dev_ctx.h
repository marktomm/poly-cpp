#ifndef _OOP_DEV_EXT_H_
#define _OOP_DEV_EXT_H_

#include "dev_base.h"

#include <memory>
#include <vector>

namespace Oop {

void statPorts(std::vector<std::unique_ptr<Port> > const&) noexcept;

void writePorts(std::vector<std::unique_ptr<Port> >&,
                BufferData const&) noexcept;

} // namespace Oop

#endif