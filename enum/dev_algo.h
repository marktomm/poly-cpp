#ifndef _ENUM_DEV_ALGO_H_
#define _ENUM_DEV_ALGO_H_

#include "dev_impl.h"

namespace Enum {

void read(TcpPort&, std::string&);
void write(TcpPort&, BufferData const&);
void stat(TcpPort const&);

void read(SerialPort&, std::string&);
void write(SerialPort&, BufferData const&);
void stat(SerialPort const&);

} // namespace Enum

#endif