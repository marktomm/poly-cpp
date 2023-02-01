#include "dev_algo.h"
#include "dev_impl.h"

#include <iostream>

void SyslogStatTcpPortStrategy::operator()(TcpPort const& p) const
{
    using namespace std;
    cout << "tcpport to syslog " << p.GetIp() << ":" << p.GetPort() << endl;
}

void SyslogStatSerialPortStrategy::operator()(SerialPort const& p) const
{
    using namespace std;
    cout << "serialport to syslog " << p.GetDev() << endl;
}

void SyncWriteTcpPortStrategy::operator()(TcpPort& p,
                                          BufferData const& data) const
{
    p.write(data);
}

void SyncWriteSerialPortStrategy::operator()(SerialPort& p,
                                             BufferData const& data) const
{
    p.write(data);
}
