#ifndef _TYPE_ERASURE_DEV_ALGO_H_
#define _TYPE_ERASURE_DEV_ALGO_H_

#include "dev_impl.h"
#include "types.h"

namespace TypeErasureUp {

void read(TcpPort&, std::string&) noexcept;
void write(TcpPort&, BufferData const&) noexcept;
void stat(TcpPort const&) noexcept;

void read(SerialPort&, std::string&) noexcept;
void write(SerialPort&, BufferData const&) noexcept;
void stat(SerialPort const&) noexcept;

} // namespace TypeErasureUp

#endif