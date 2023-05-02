#ifndef _ENUM_DEV_ALGO_H_
#define _ENUM_DEV_ALGO_H_

#include "dev_impl.h"
#include "types.h"

namespace Enum {

void read(TcpPort const&, BufferData&) noexcept;
void write(TcpPort&, BufferData const&) noexcept;

void read(SerialPort const&, BufferData&) noexcept;
void write(SerialPort&, BufferData const&) noexcept;

} // namespace Enum

#endif