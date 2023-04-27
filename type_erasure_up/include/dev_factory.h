#ifndef _TYPE_ERASURE_UP_DEV_FACTORY_H_
#define _TYPE_ERASURE_UP_DEV_FACTORY_H_

#include "dev_base.h"

#include <memory>
#include <string>

#include <cstdint>

namespace TypeErasureUp {

Readable createTcpPort(std::string ip, uint16_t port) noexcept;

Readable createSerialPort(std::string dev) noexcept;

} // namespace TypeErasureUp

#endif