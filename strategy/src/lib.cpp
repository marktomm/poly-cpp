#include "lib.h"

namespace strategy {} // namespace strategy
// strategy/src/dev_impl.cpp

namespace strategy {

void TcpPort::Read(BufferData& output) const noexcept { strategy_(output); }

void TcpPort::Write(BufferData const& data) noexcept { wStrat_(data); }

void SerialPort::Read(BufferData& output) const noexcept { strategy_(output); }

void SerialPort::Write(BufferData const& data) noexcept { wStrat_(data); }

void TcpPort::SetReadStrat(ReadBaseStrategy s) noexcept { strategy_ = s; }

void TcpPort::SetWriteStrat(WriteBaseStrategy s) noexcept { wStrat_ = s; }

void SerialPort::SetReadStrat(ReadBaseStrategy s) noexcept { strategy_ = s; }

void SerialPort::SetWriteStrat(WriteBaseStrategy s) noexcept { wStrat_ = s; }

} // namespace strategy
// strategy/src/dev_impl.cpp end
// strategy/src/dev_algo.cpp

#include <iostream>

namespace strategy {
static void escape(void* p) { asm volatile("" : : "g"(p) : "memory"); }

void SyslogReadStrategy::operator()(BufferData& output) const noexcept {
    escape(&output);
}

void SyncWriteStrategy::operator()(BufferData const& data) const noexcept {
    escape(&const_cast<BufferData&>(data));
}

void UnbufferedWriteStrategy::operator()(
    BufferData const& data) const noexcept {
    escape(&const_cast<BufferData&>(data));
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
                                    ReadBaseStrategy strategy,
                                    WriteBaseStrategy wStrat) noexcept {
    return std::make_unique<TcpPort>(ip, port, strategy, wStrat);
}

std::unique_ptr<Port> createSerialPort(std::string dev,
                                       ReadBaseStrategy strategy,
                                       WriteBaseStrategy wStrat) noexcept {
    return std::make_unique<SerialPort>(dev, strategy, wStrat);
}

} // namespace strategy
// strategy/src/dev_factory.cpp end

#include <algorithm>
#include <random>

namespace strategy {

using namespace std;
using namespace common;

vup StrategyPortsInitRandom(common::vu32& v) {
    using namespace strategy;
    using Ports = std::vector<std::unique_ptr<Port> >;

    Ports ports(100);
    for (uint32_t i = 0; i < 50; ++i) {
        ports[v[i]] = createTcpPort("localhost", 2404, SyslogReadStrategy{},
                                    SyncWriteStrategy{});
    }
    for (uint32_t i = 50; i < 100; ++i) {
        ports[v[i]] = createSerialPort("/dev/ttyUSB0", SyslogReadStrategy{},
                                       SyncWriteStrategy{});
    }

    return ports;
}

} // namespace strategy