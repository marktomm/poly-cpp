#include "dev_algo.h"

#include <iostream>

namespace type_erasure_up {

void write(TcpPort& p, BufferData const& data) noexcept { p.Write(data); }
void read(TcpPort const& p, BufferData& output) noexcept { p.Read(output); }

void write(SerialPort& p, BufferData const& data) noexcept { p.Write(data); }
void read(SerialPort const& p, BufferData& output) noexcept { p.Read(output); }

} // namespace type_erasure_up