#include "dev_factory.h"
#include "dev_impl.h"

#include <memory>

namespace VariantT {

Port createTcpPort(std::string ip, uint16_t port) noexcept
{
    return TcpPort(ip, port);
}

Port createSerialPort(std::string dev) noexcept { return SerialPort(dev); }

} // namespace VariantT
