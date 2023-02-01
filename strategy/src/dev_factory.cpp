#include "dev_base.h"
#include "dev_impl.h"

#include <memory>

std::unique_ptr<Port> CreateTcpPort(std::string ip, uint16_t port,
                                    StatTcpPortStrategy strategy,
                                    WriteTcpPortStrategy wStrat)
{
    return std::make_unique<TcpPort>(ip, port, strategy, wStrat);
}

std::unique_ptr<Port> CreateSerialPort(std::string dev,
                                       StatSerialPortStrategy strategy,
                                       WriteSerialPortStrategy wStrat)
{
    return std::make_unique<SerialPort>(dev, strategy, wStrat);
}
