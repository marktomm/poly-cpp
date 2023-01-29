#include "dev_impl.h"

namespace Visit {

std::string TcpPort::GetIp() const { return ip_; }
uint16_t TcpPort::GetPort() const { return port_; }

std::string SerialPort::GetDev() const { return dev_; }

void TcpPort::Write(BufferData const& data) const noexcept { buf_ += data; }

void SerialPort::Write(BufferData const& data) const noexcept { buf_ += data; }

void TcpPort::accept(Visitor const& v) { v.visit(*this); }

void SerialPort::accept(Visitor const& v) { v.visit(*this); }

} // namespace Visit