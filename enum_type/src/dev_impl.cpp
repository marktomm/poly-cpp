#include "dev_impl.h"

namespace Enum {

void TcpPort::Read(BufferData& data) const noexcept { data = buf_; }

void TcpPort::Write(BufferData const& data) noexcept { buf_ += data; }

void SerialPort::Read(BufferData& data) const noexcept { data = buf_; };

void SerialPort::Write(BufferData const& data) noexcept { buf_ += data; }

} // namespace Enum