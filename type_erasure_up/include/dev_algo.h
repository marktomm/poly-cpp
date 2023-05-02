#ifndef _TYPE_ERASURE_DEV_ALGO_H_
#define _TYPE_ERASURE_DEV_ALGO_H_

#include "dev_impl.h"
#include "types.h"

namespace type_erasure_up {

void read(TcpPort const&, BufferData&) noexcept;
void write(TcpPort&, BufferData const&) noexcept;

void read(SerialPort const&, BufferData&) noexcept;
void write(SerialPort&, BufferData const&) noexcept;

} // namespace type_erasure_up

#endif