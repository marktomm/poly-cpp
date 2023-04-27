#include "dev_impl.h"

namespace Enum {

void TcpPort::Write(BufferData const& data) noexcept { buf_ += data; }

void SerialPort::Write(BufferData const& data) noexcept { buf_ += data; }

} // namespace Enum