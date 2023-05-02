#include "dev_impl.h"

#include <memory>

namespace visitor {

std::unique_ptr<Port> createTcpPort(std::string ip, uint16_t port) noexcept {
    return std::make_unique<TcpPort>(ip, port);
}

std::unique_ptr<Port> createSerialPort(std::string dev) noexcept {
    return std::make_unique<SerialPort>(dev);
}

} // namespace visitor