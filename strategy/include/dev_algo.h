#ifndef _STRATEGY_DEV_ALGO_H_
#define _STRATEGY_DEV_ALGO_H_

#include "dev_base.h"

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

#endif