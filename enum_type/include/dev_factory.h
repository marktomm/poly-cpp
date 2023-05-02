#ifndef _ENUM_DEV_FACTORY_H_
#define _ENUM_DEV_FACTORY_H_

#include "dev_base.h"

#include <memory>
#include <string>

#include <cstdint>

namespace Enum {

std::unique_ptr<Port> createTcpPort(std::string ip, uint16_t port) noexcept;

std::unique_ptr<Port> createSerialPort(std::string dev) noexcept;

} // namespace Enum

#endif