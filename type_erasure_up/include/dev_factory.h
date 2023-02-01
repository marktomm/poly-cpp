#ifndef _OOP_DEV_FACTORY_H_
#define _OOP_DEV_FACTORY_H_

#include "dev_base.h"

#include <memory>
#include <string>

#include <cstdint>

namespace TypeErasureUp {

statable createTcpPort(std::string ip, uint16_t port) noexcept;

statable createSerialPort(std::string dev) noexcept;

} // namespace TypeErasureUp

#endif