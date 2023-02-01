#ifndef _VARIANT_DEV_EXT_H_
#define _VARIANT_DEV_EXT_H_

#include "dev_impl.h"
#include "types.h"

#include <variant>

#include <memory>
#include <vector>

using Port = std::variant<TcpPort, SerialPort>;
using WriteData = std::variant<BufferData>;

void statPorts(std::vector<Port> const&);

void writePorts(std::vector<Port>&, WriteData const&);

#endif