#include "dev_impl.h"

namespace Strategy {

void TcpPort::Read(BufferData& output) const noexcept { output = buf_; }

void TcpPort::Write(BufferData const& data) noexcept { buf_ += data; }

void SerialPort::Read(BufferData& output) const noexcept { output = buf_; }

void SerialPort::Write(BufferData const& data) noexcept { buf_ += data; }

} // namespace Strategy