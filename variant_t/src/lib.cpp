#include "lib.h"

namespace variant_t {} // namespace variant_t
// variant_t/src/dev_impl.cpp

namespace variant_t {

void TcpPort::Read(BufferData& data) const noexcept { data = buf_; }

void TcpPort::Write(BufferData const& data) noexcept { buf_ += data; }

void SerialPort::Read(BufferData& data) const noexcept { data = buf_; }

void SerialPort::Write(BufferData const& data) noexcept { buf_ += data; }

} // namespace variant_t
// variant_t/src/dev_impl.cpp end
// variant_t/src/dev_algo.cpp

#include <iostream>

namespace variant_t {

void Read::operator()(TcpPort const& p, BufferData& output) const noexcept {
    p.Read(output);
}

void Read::operator()(SerialPort const& p, BufferData& output) const noexcept {
    p.Read(output);
}

void Write::operator()(TcpPort& p, BufferData const& data) const noexcept {
    p.Write(data);
}

void Write::operator()(SerialPort& p, BufferData const& data) const noexcept {
    p.Write(data);
}

} // namespace variant_t
// variant_t/src/dev_algo.cpp end
// variant_t/src/dev_ctx.cpp
#include <vector>

namespace variant_t {

void readPorts(std::vector<Port> const& ports, ReadData& output) noexcept {
    for (auto const& p : ports) {
        std::visit(Read{}, p, output);
    }
}

void writePorts(std::vector<Port>& ports, WriteData const& data) noexcept {
    for (auto& p : ports) {
        std::visit(Write{}, p, data);
    }
}

} // namespace variant_t
// variant_t/src/dev_ctx.cpp end
// variant_t/src/dev_factory.cpp

#include <memory>

namespace variant_t {

Port createTcpPort(std::string ip, uint16_t port) noexcept {
    return TcpPort(ip, port);
}

Port createSerialPort(std::string dev) noexcept { return SerialPort(dev); }

} // namespace variant_t
// variant_t/src/dev_factory.cpp end

namespace variant_t {

using namespace std;
using namespace common;

vup VarianttPortsInitRandom(common::vu32& v) {
    using namespace variant_t;
    using Ports = std::vector<Port>;

    Ports ports;
    for (uint32_t i = 0; i < common::VCOUNTHALF; ++i) {
        ports.push_back(createTcpPort("localhost", 2404));
    }
    for (uint32_t i = common::VCOUNTHALF; i < common::VCOUNT; ++i) {
        ports.push_back(createSerialPort("/dev/ttyUSB0"));
    }

    rreorder(ports, v);

    return ports;
}

std::string GetStatus::operator()(TcpPort const&) const noexcept {
    return "noop";
}

std::string GetStatus::operator()(Firewall const&) const noexcept {
    return "noop";
}

} // namespace variant_t