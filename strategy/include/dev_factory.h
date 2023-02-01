#ifndef _OOP_DEV_FACTORY_H_
#define _OOP_DEV_FACTORY_H_

#include "dev_base.h"

#include <memory>
#include <string>

#include <cstdint>

namespace Strategy {

std::unique_ptr<Port> CreateTcpPort(std::string ip, uint16_t port,
                                    StatTcpPortStrategy, WriteTcpPortStrategy);

std::unique_ptr<Port> CreateSerialPort(std::string dev, StatSerialPortStrategy,
                                       WriteSerialPortStrategy);

} // namespace Strategy

#endif