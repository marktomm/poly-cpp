#ifndef _TYPE_ERASURE_DEV_ALGO_H_
#define _TYPE_ERASURE_DEV_ALGO_H_

#include "dev_impl.h"
#include "types.h"

void read(TcpPort&, std::string&);
void write(TcpPort&, BufferData const&);
void stat(TcpPort const&);

void read(SerialPort&, std::string&);
void write(SerialPort&, BufferData const&);
void stat(SerialPort const&);

#endif