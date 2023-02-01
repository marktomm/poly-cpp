#ifndef _STRATEGY_DEV_EXT_H_
#define _STRATEGY_DEV_EXT_H_

#include "dev_base.h"
#include "types.h"

#include <memory>
#include <vector>

namespace Strategy {

void statPorts(std::vector<std::unique_ptr<Port> > const&);

void writePorts(std::vector<std::unique_ptr<Port> > const&, BufferData const&);

} // namespace Strategy

#endif