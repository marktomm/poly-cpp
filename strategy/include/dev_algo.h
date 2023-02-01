#ifndef _STRATEGY_DEV_ALGO_H_
#define _STRATEGY_DEV_ALGO_H_

#include "dev_base.h"

namespace Strategy {

class SyslogStatTcpPortStrategy
{
public:
    void operator()(TcpPort const&) const;
};

class SyslogStatSerialPortStrategy
{
public:
    void operator()(SerialPort const&) const;
};

class SyncWriteTcpPortStrategy
{
public:
    void operator()(TcpPort&, BufferData const&) const;
};

class SyncWriteSerialPortStrategy
{
public:
    void operator()(SerialPort&, BufferData const&) const;
};

} // namespace Strategy

#endif