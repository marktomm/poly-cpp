#include "lib.h"

namespace visitor {} // namespace visitor
// visitor/src/dev_impl.cpp

namespace visitor {

void TcpPort::Read(BufferData& data) const noexcept { data = buf_; }

void TcpPort::Write(BufferData const& data) noexcept { buf_ += data; }

void SerialPort::Read(BufferData& data) const noexcept { data = buf_; }

void SerialPort::Write(BufferData const& data) noexcept { buf_ += data; }

void TcpPort::accept(Visitor const& v) const noexcept { v.visit(*this); }

void SerialPort::accept(Visitor const& v) const noexcept { v.visit(*this); }

void TcpPort::accept(Visitor const& v) noexcept { v.visit(*this); }

void SerialPort::accept(Visitor const& v) noexcept { v.visit(*this); }

} // namespace visitor
// visitor/src/dev_impl.cpp end
// visitor/src/dev_algo.cpp

#include <iostream>

namespace visitor {

void Read::visit(TcpPort const& p) const noexcept { p.Read(data_); }

void Read::visit(SerialPort const& p) const noexcept { p.Read(data_); }

void Read::visit(TcpPort&) const noexcept {
    // unused
}

void Read::visit(SerialPort&) const noexcept {
    // unused
}

void Write::visit(TcpPort const&) const noexcept {
    // unused
}

void Write::visit(SerialPort const&) const noexcept {
    // unused
}

void Write::visit(TcpPort& p) const noexcept { p.Write(data_); }

void Write::visit(SerialPort& p) const noexcept { p.Write(data_); }

} // namespace visitor
// visitor/src/dev_algo.cpp end
// visitor/src/dev_ctx.cpp

namespace visitor {

void readPorts(std::vector<std::unique_ptr<Port> > const& ports,
               BufferData& output) noexcept {
    for (auto const& p : ports) {
        p->accept(Read{output});
    }
}

void writePorts(std::vector<std::unique_ptr<Port> >& ports,
                BufferData const& data) noexcept {
    for (auto& p : ports) {
        p->accept(Write{data});
    }
}

} // namespace visitor
// visitor/src/dev_ctx.cpp end
// visitor/src/dev_factory.cpp

#include <memory>

namespace visitor {

std::unique_ptr<Port> createTcpPort(std::string ip, uint16_t port) noexcept {
    return std::make_unique<TcpPort>(ip, port);
}

std::unique_ptr<Port> createSerialPort(std::string dev) noexcept {
    return std::make_unique<SerialPort>(dev);
}

} // namespace visitor
// visitor/src/dev_factory.cpp end

namespace visitor {

using namespace std;
using namespace common;

vup VisitPortsInitRandom(common::vu32& v) {
    using namespace visitor;
    using Ports = std::vector<std::unique_ptr<Port> >;

    Ports ports(100);
    for (uint32_t i = 0; i < 50; ++i) {
        ports[v[i]] = createTcpPort("localhost", 2404);
    }
    for (uint32_t i = 50; i < 100; ++i) {
        ports[v[i]] = createSerialPort("/dev/ttyUSB0");
    }

    return ports;
}

} // namespace visitor