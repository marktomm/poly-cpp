#include "lib.h"

namespace strategy {} // namespace strategy
// strategy/src/dev_impl.cpp

namespace strategy {

void TcpPort::Read(BufferData& output) const noexcept { output = buf_; }

void TcpPort::Write(BufferData const& data) noexcept { buf_ += data; }

void SerialPort::Read(BufferData& output) const noexcept { output = buf_; }

void SerialPort::Write(BufferData const& data) noexcept { buf_ += data; }

} // namespace strategy
// strategy/src/dev_impl.cpp end
// strategy/src/dev_algo.cpp

#include <iostream>

namespace strategy {

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

} // namespace strategy
// strategy/src/dev_algo.cpp end
// strategy/src/dev_ctx.cpp

namespace strategy {

void readPorts(std::vector<std::unique_ptr<Port> > const& ports,
               BufferData& output) noexcept {
    for (auto const& p : ports) {
        p->Read(output);
    }
}

void writePorts(std::vector<std::unique_ptr<Port> > const& ports,
                BufferData const& data) noexcept {
    for (auto const& p : ports) {
        p->Write(data);
    }
}

} // namespace strategy
// strategy/src/dev_ctx.cpp end
// strategy/src/dev_factory.cpp

#include <memory>

namespace strategy {

std::unique_ptr<Port> createTcpPort(std::string ip, uint16_t port,
                                    ReadTcpPortStrategy strategy,
                                    WriteTcpPortStrategy wStrat) noexcept {
    return std::make_unique<TcpPort>(ip, port, strategy, wStrat);
}

std::unique_ptr<Port>
createSerialPort(std::string dev, ReadSerialPortStrategy strategy,
                 WriteSerialPortStrategy wStrat) noexcept {
    return std::make_unique<SerialPort>(dev, strategy, wStrat);
}

} // namespace strategy
// strategy/src/dev_factory.cpp end
