#ifndef _STRATEGY_DEV_FACTORY_H_
#define _STRATEGY_DEV_FACTORY_H_

#include "dev_base.h"

#include <memory>
#include <string>

#include <cstdint>

namespace strategy {

std::unique_ptr<Port> createTcpPort(std::string ip, uint16_t port,
                                    ReadTcpPortStrategy,
                                    WriteTcpPortStrategy) noexcept;

std::unique_ptr<Port> createSerialPort(std::string dev, ReadSerialPortStrategy,
                                       WriteSerialPortStrategy) noexcept;

} // namespace strategy

#endif