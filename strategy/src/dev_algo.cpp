#include "dev_algo.h"
#include "dev_impl.h"

#include <iostream>

namespace Strategy {

void SyslogReadTcpPortStrategy::operator()(TcpPort const& p,
                                           BufferData& output) const noexcept {
    p.Read(output);
}

void SyslogReadSerialPortStrategy::operator()(
    SerialPort const& p, BufferData& output) const noexcept {
    p.Read(output);
}

void SyncWriteTcpPortStrategy::operator()(
    TcpPort& p, BufferData const& data) const noexcept {
    p.Write(data);
}

void SyncWriteSerialPortStrategy::operator()(
    SerialPort& p, BufferData const& data) const noexcept {
    p.Write(data);
}

} // namespace Strategy
