#include "dev_impl.h"

namespace Visit {

std::string TcpPort::GetIp() const noexcept { return ip_; }
uint16_t TcpPort::GetPort() const noexcept { return port_; }

std::string SerialPort::GetDev() const noexcept { return dev_; }

void TcpPort::Write(BufferData const& data) const noexcept { buf_ += data; }

void SerialPort::Write(BufferData const& data) const noexcept { buf_ += data; }

void TcpPort::accept(Visitor const& v) const noexcept { v.visit(*this); }

void SerialPort::accept(Visitor const& v) const noexcept { v.visit(*this); }

} // namespace Visit