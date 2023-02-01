#ifndef _VISITOR_DEV_EXT_H_
#define _VISITOR_DEV_EXT_H_

#include "dev_base.h"
#include "types.h"

#include <memory>
#include <vector>

namespace Visit {

void statPorts(std::vector<std::unique_ptr<Port> > const&) noexcept;

void writePorts(std::vector<std::unique_ptr<Port> >&,
                BufferData const&) noexcept;

} // namespace Visit

#endif