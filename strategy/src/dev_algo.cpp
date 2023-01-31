#include "dev_algo.h"
#include "dev_impl.h"

#include <iostream>

void SyslogStatTcpPortStrategy::operator()(const TcpPort& p) const
{
    using namespace std;
    cout << "tcpport to syslog " << p.GetIp() << ":" << p.GetPort() << endl;
}

void SyslogStatSerialPortStrategy::operator()(const SerialPort& p) const
{
    using namespace std;
    cout << "serialport to syslog " << p.GetDev() << endl;
}