#include "lib.h"

namespace oop {} // namespace oop
// oop/src/dev_impl.cpp

#include <iostream>

namespace oop {

void TcpPort::Read(BufferData& data) const noexcept { data = buf_; }

void TcpPort::Write(BufferData const& data) noexcept { buf_ += data; }

void SerialPort::Read(BufferData& data) const noexcept { data = buf_; }

void SerialPort::Write(BufferData const& data) noexcept { buf_ += data; }

} // namespace oop
// oop/src/dev_impl.cpp end
// oop/src/dev_ctx.cpp

namespace oop {

void readPorts(std::vector<std::unique_ptr<Port> > const& ports,
               BufferData& data) noexcept {
    for (auto const& p : ports) {
        p->Read(data);
    }
}

void writePorts(std::vector<std::unique_ptr<Port> >& ports,
                BufferData const& data) noexcept {
    for (auto const& p : ports) {
        p->Write(data);
    }
}

} // namespace oop
// oop/src/dev_ctx.cpp end
// oop/src/dev_factory.cpp

#include <memory>

namespace oop {

std::unique_ptr<Port> createTcpPort(std::string ip, uint16_t port) noexcept {
    return std::make_unique<TcpPort>(ip, port);
}

std::unique_ptr<Port> createSerialPort(std::string dev) noexcept {
    return std::make_unique<SerialPort>(dev);
}

} // namespace oop
// oop/src/dev_factory.cpp end

#include <algorithm>
#include <random>

namespace oop {

using namespace std;
using namespace common;

vup OopPortsInitRandom(common::vu32& v) {
    using namespace oop;
    using Ports = vector<unique_ptr<Port> >;

    Ports ports(common::VCOUNT);
    for (uint32_t i = 0; i < common::VCOUNTHALF; ++i) {
        ports[v[i]] = createTcpPort("localhost", 2404);
    }
    for (uint32_t i = common::VCOUNTHALF; i < common::VCOUNT; ++i) {
        ports[v[i]] = createSerialPort("/dev/ttyUSB0");
    }

    return ports;
}

} // namespace oop