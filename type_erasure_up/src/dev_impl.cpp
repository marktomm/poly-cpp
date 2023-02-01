#include "dev_impl.h"
#include "types.h"

namespace TypeErasureUp {

std::string TcpPort::GetIp() const noexcept { return ip_; }
uint16_t TcpPort::GetPort() const noexcept { return port_; }
void TcpPort::Write(BufferData const& data) noexcept { buf_ += data; }

std::string SerialPort::GetDev() const noexcept { return dev_; }
void SerialPort::Write(BufferData const& data) noexcept { buf_ += data; }

} // namespace TypeErasureUp