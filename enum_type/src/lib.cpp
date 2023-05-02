#include "lib.h"

namespace enum_type {

} // namespace enum_type
// enum_type/src/dev_impl.cpp

namespace Enum {

void TcpPort::Read(BufferData& data) const noexcept { data = buf_; }

void TcpPort::Write(BufferData const& data) noexcept { buf_ += data; }

void SerialPort::Read(BufferData& data) const noexcept { data = buf_; };

void SerialPort::Write(BufferData const& data) noexcept { buf_ += data; }

} // namespace Enum
// enum_type/src/dev_impl.cpp end
// enum_type/src/dev_algo.cpp


#include <iostream>

namespace Enum {

void read(TcpPort const& port, BufferData& data) noexcept { port.Read(data); }
void write(TcpPort& port, BufferData const& data) noexcept { port.Write(data); }

void read(SerialPort const& port, BufferData& data) noexcept {
    port.Read(data);
}
void write(SerialPort& port, BufferData const& data) noexcept {
    port.Write(data);
}

} // namespace Enum
// enum_type/src/dev_algo.cpp end
// enum_type/src/dev_ctx.cpp

namespace Enum {

void readPorts(std::vector<std::unique_ptr<Port> > const& ports,
               BufferData& output) noexcept {
    for (auto const& p : ports) {
        readPort(p, output);
    }
}

void readPort(std::unique_ptr<Port> const& port, BufferData& output) noexcept {
    switch (port->GetType()) {
    case tcp:
        read(*static_cast<TcpPort const*>(port.get()), output);
        break;
    case serial:
        read(*static_cast<SerialPort const*>(port.get()), output);
        break;
    default:
        break;
    }
}

void writePorts(std::vector<std::unique_ptr<Port> >& ports,
                BufferData const& data) noexcept {
    for (auto& p : ports) {
        writePort(p, data);
    }
}

void writePort(std::unique_ptr<Port>& port, BufferData const& data) noexcept {
    switch (port->GetType()) {
    case tcp:
        write(*static_cast<TcpPort*>(port.get()), data);
        break;
    case serial:
        write(*static_cast<SerialPort*>(port.get()), data);
        break;
    default:
        break;
    }
}

} // namespace Enum
// enum_type/src/dev_ctx.cpp end
// enum_type/src/dev_factory.cpp

#include <memory>

namespace Enum {

std::unique_ptr<Port> createTcpPort(std::string ip, uint16_t port) noexcept {
    return std::make_unique<TcpPort>(ip, port);
}

std::unique_ptr<Port> createSerialPort(std::string dev) noexcept {
    return std::make_unique<SerialPort>(dev);
}

} // namespace Enum
// enum_type/src/dev_factory.cpp end
