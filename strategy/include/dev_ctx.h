#ifndef _STRATEGY_DEV_EXT_H_
#define _STRATEGY_DEV_EXT_H_

#include "dev_base.h"
#include "types.h"

#include <memory>
#include <vector>

namespace Strategy {

void statPorts(std::vector<std::unique_ptr<Port> > const&) noexcept;

void writePorts(std::vector<std::unique_ptr<Port> > const&,
                BufferData const&) noexcept;

} // namespace Strategy

#endif