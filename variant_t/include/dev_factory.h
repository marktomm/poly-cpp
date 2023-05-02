#ifndef _VARIANT_T_DEV_FACTORY_H_
#define _VARIANT_T_DEV_FACTORY_H_

#include "dev_ctx.h"

#include <memory>
#include <string>

#include <cstdint>

namespace variant_t {

Port createTcpPort(std::string ip, uint16_t port) noexcept;

Port createSerialPort(std::string dev) noexcept;

} // namespace variant_t

#endif