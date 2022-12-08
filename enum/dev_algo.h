#ifndef _ENUM_DEV_ALGO_H_
#define _ENUM_DEV_ALGO_H_

#include "dev_impl.h"

void read(TcpPort&, std::string&);
void write(TcpPort&, std::string const&);
void stat(TcpPort const&);

void read(SerialPort&, std::string&);
void write(SerialPort&, std::string const&);
void stat(SerialPort const&);

#endif