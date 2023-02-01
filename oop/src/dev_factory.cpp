#include "dev_factory.h"
#include "dev_impl.h"

#include <memory>

namespace Oop {

std::unique_ptr<Port> createTcpPort(std::string ip, uint16_t port)
{
    return std::make_unique<TcpPort>(ip, port);
}

std::unique_ptr<Port> createSerialPort(std::string dev)
{
    return std::make_unique<SerialPort>(dev);
}

} // namespace Oop
