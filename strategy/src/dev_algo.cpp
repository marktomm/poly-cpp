#include "dev_algo.h"
#include "dev_impl.h"

#include <iostream>

namespace Strategy {

void SyslogStatTcpPortStrategy::operator()(TcpPort const& p) const noexcept {
    using namespace std;
    cout << "tcpport to syslog " << p.GetIp() << ":" << p.GetPort() << endl;
}

void SyslogStatSerialPortStrategy::operator()(
    SerialPort const& p) const noexcept {
    using namespace std;
    cout << "serialport to syslog " << p.GetDev() << endl;
}

void SyncWriteTcpPortStrategy::operator()(
    TcpPort& p, BufferData const& data) const noexcept {
    p.write(data);
}

void SyncWriteSerialPortStrategy::operator()(
    SerialPort& p, BufferData const& data) const noexcept {
    p.write(data);
}

} // namespace Strategy
