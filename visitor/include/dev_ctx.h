#ifndef _VISITOR_DEV_EXT_H_
#define _VISITOR_DEV_EXT_H_

#include "types.h"
#include "dev_base.h"

#include <memory>
#include <vector>

namespace Visit {

void statPorts(std::vector<std::unique_ptr<Port> > const&);

void writePorts(std::vector<std::unique_ptr<Port> >&, BufferData const&);

} // namespace Visit

#endif