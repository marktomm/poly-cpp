#include "dev_impl.h"

namespace Strategy {

std::string TcpPort::GetIp() const noexcept { return ip_; }
uint16_t TcpPort::GetPort() const noexcept { return port_; }

std::string SerialPort::GetDev() const noexcept { return dev_; }

void TcpPort::read(std::string&) noexcept {}

void TcpPort::write(BufferData const& data) noexcept { buf_ += data; }

void TcpPort::stat() const noexcept { strategy_(*this); }

void SerialPort::read(std::string&) noexcept {}

void SerialPort::write(BufferData const& data) noexcept { buf_ += data; }

void SerialPort::stat() const noexcept { strategy_(*this); }

} // namespace Strategy