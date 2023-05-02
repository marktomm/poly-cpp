
#include "dev_algo.h"

#include <iostream>

namespace Enum {

void read(TcpPort const& port, BufferData& data) noexcept { port.Read(data); }
void write(TcpPort& port, BufferData const& data) noexcept { port.Write(data); }

void read(SerialPort const& port, BufferData& data) noexcept {
    port.Read(data);
}
void write(SerialPort& port, BufferData const& data) noexcept {
    port.Write(data);
}

} // namespace Enum