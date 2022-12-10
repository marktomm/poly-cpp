#include "dev_impl.h"

#include <memory>

std::unique_ptr<Port> CreateTcpPort(std::string ip, uint16_t port)
{
    return std::make_unique<TcpPort>(ip, port);
}

std::unique_ptr<Port> CreateSerialPort(std::string dev)
{
    return std::make_unique<SerialPort>(dev);
}
