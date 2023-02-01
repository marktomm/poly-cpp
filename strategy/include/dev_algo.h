#ifndef _STRATEGY_DEV_ALGO_H_
#define _STRATEGY_DEV_ALGO_H_

#include "dev_base.h"

namespace Strategy {

class SyslogStatTcpPortStrategy
{
public:
    void operator()(TcpPort const&) const noexcept;
};

class SyslogStatSerialPortStrategy
{
public:
    void operator()(SerialPort const&) const noexcept;
};

class SyncWriteTcpPortStrategy
{
public:
    void operator()(TcpPort&, BufferData const&) const noexcept;
};

class SyncWriteSerialPortStrategy
{
public:
    void operator()(SerialPort&, BufferData const&) const noexcept;
};

} // namespace Strategy

#endif