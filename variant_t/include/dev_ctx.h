#ifndef _VARIANT_DEV_EXT_H_
#define _VARIANT_DEV_EXT_H_

#include "dev_impl.h"

#include <variant>

#include <memory>
#include <vector>

using Port = std::variant<TcpPort, SerialPort>;

void statPorts(std::vector<Port> const& shapes);

#endif