#ifndef _DEV_EXT_H_
#define _DEV_EXT_H_

#include "dev_base.h"

#include <memory>
#include <vector>

namespace Enum {

void statPorts(std::vector<std::unique_ptr<Port> > const&);

void statPort(std::unique_ptr<Port> const&);

void writePorts(std::vector<std::unique_ptr<Port> >&, BufferData const&);

void writePort(std::unique_ptr<Port>&, BufferData const&);

} // namespace Enum

#endif