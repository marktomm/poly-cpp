#ifndef _STRATEGY_DEV_ALGO_H_
#define _STRATEGY_DEV_ALGO_H_

#include "dev_base.h"

namespace Strategy {

class SyslogReadTcpPortStrategy {
public:
    void operator()(TcpPort const&, BufferData&) const noexcept;
};

class SyslogReadSerialPortStrategy {
public:
    void operator()(SerialPort const&, BufferData&) const noexcept;
};

class SyncWriteTcpPortStrategy {
public:
    void operator()(TcpPort&, BufferData const&) const noexcept;
};

class SyncWriteSerialPortStrategy {
public:
    void operator()(SerialPort&, BufferData const&) const noexcept;
};

} // namespace Strategy

#endif