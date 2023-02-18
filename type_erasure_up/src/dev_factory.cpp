#include "dev_factory.h"
#include "dev_algo.h"
#include "dev_impl.h"

#include <memory>

namespace TypeErasureUp {

statable createTcpPort(std::string ip, uint16_t port) noexcept {
    return TcpPort(ip, port);
}

statable createSerialPort(std::string dev) noexcept { return SerialPort(dev); }

} // namespace TypeErasureUp
