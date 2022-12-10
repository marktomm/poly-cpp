#include "dev_impl.h"

#include <memory>

std::unique_ptr<Port> CreateTcpPort(std::string ip, uint16_t port,
                                    StatTcpPortStrategy strategy)
{
    return std::make_unique<TcpPort>(ip, port, strategy);
}

std::unique_ptr<Port> CreateSerialPort(std::string dev,
                                       StatSerialPortStrategy strategy)
{
    return std::make_unique<SerialPort>(dev, strategy);
}
