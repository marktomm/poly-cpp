#include "dev_impl.h"

namespace Visit {

void TcpPort::Read(BufferData& data) const noexcept { data = buf_; }

void TcpPort::Write(BufferData const& data) noexcept { buf_ += data; }

void SerialPort::Read(BufferData& data) const noexcept { data = buf_; }

void SerialPort::Write(BufferData const& data) noexcept { buf_ += data; }

void TcpPort::accept(Visitor const& v) const noexcept { v.visit(*this); }

void SerialPort::accept(Visitor const& v) const noexcept { v.visit(*this); }

void TcpPort::accept(Visitor const& v) noexcept { v.visit(*this); }

void SerialPort::accept(Visitor const& v) noexcept { v.visit(*this); }

} // namespace Visit