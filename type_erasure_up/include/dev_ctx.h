#ifndef _TYPE_ERASURE_DEV_EXT_H_
#define _TYPE_ERASURE_DEV_EXT_H_

#include "dev_base.h"
#include "types.h"

#include <memory>
#include <vector>

namespace TypeErasureUp {

void statPorts(std::vector<statable> const&);

void writePorts(std::vector<statable>&, BufferData const&);

} // namespace TypeErasureUp

#endif