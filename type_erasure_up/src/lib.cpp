#include "lib.h"

namespace type_erasure_up {} // namespace type_erasure_up
// type_erasure_up/src/dev_impl.cpp

namespace type_erasure_up {

void TcpPort::Read(BufferData& data) const noexcept { data = buf_; }

void TcpPort::Write(BufferData const& data) noexcept { buf_ += data; }

void SerialPort::Read(BufferData& data) const noexcept { data = buf_; }

void SerialPort::Write(BufferData const& data) noexcept { buf_ += data; }

} // namespace type_erasure_up
// type_erasure_up/src/dev_impl.cpp end
// type_erasure_up/src/dev_algo.cpp

#include <iostream>

namespace type_erasure_up {

void write(TcpPort& p, BufferData const& data) noexcept { p.Write(data); }
void read(TcpPort const& p, BufferData& output) noexcept { p.Read(output); }

void write(SerialPort& p, BufferData const& data) noexcept { p.Write(data); }
void read(SerialPort const& p, BufferData& output) noexcept { p.Read(output); }

} // namespace type_erasure_up
// type_erasure_up/src/dev_algo.cpp end
// type_erasure_up/src/dev_ctx.cpp

namespace type_erasure_up {

void read(std::vector<Readable> const& doc, BufferData& output) noexcept {
    for (auto const& it : doc) {
        read(it, output);
    }
}

void write(std::vector<Readable>& doc, BufferData const& data) noexcept {
    for (auto& it : doc) {
        write(it, data);
    }
}

void readPorts(std::vector<Readable> const& ports,
               BufferData& output) noexcept {
    read(ports, output);
}

void writePorts(std::vector<Readable>& ports, BufferData const& data) noexcept {
    write(ports, data);
}

void swap(Readable& a, Readable& b) { a.swap(b); }

} // namespace type_erasure_up
// type_erasure_up/src/dev_ctx.cpp end
// type_erasure_up/src/dev_factory.cpp

#include <memory>

namespace type_erasure_up {

Readable createTcpPort(std::string ip, uint16_t port) noexcept {
    return TcpPort(ip, port);
}

Readable createSerialPort(std::string dev) noexcept { return SerialPort(dev); }

} // namespace type_erasure_up
// type_erasure_up/src/dev_factory.cpp end
