#include "lib.h"

using namespace std;
using namespace enum_type;

namespace enum_type {} // namespace enum_type
// enum_type/src/dev_impl.cpp

static void escape(void* p) { asm volatile("" : : "g"(p) : "memory"); }

namespace Enum {

void TcpPort::Read(BufferData& data) const noexcept {
    data = buf_;
    escape(&data); // this has no effect here and below 3
}

void TcpPort::Write(BufferData const& data) noexcept {
    buf_ += data;
    escape(&buf_);
}

void SerialPort::Read(BufferData& data) const noexcept {
    data = buf_;
    escape(&data);
};

void SerialPort::Write(BufferData const& data) noexcept {
    buf_ += data;
    escape(&buf_);
}

} // namespace Enum
// enum_type/src/dev_impl.cpp end
// enum_type/src/dev_algo.cpp

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

void readPorts(vector<unique_ptr<Port> > const& ports,
               BufferData& output) noexcept {
    for (auto const& p : ports) {
        readPort(p, output);
    }
}

void readPort(unique_ptr<Port> const& port, BufferData& output) noexcept {
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

void writePorts(vector<unique_ptr<Port> >& ports,
                BufferData const& data) noexcept {
    for (auto& p : ports) {
        writePort(p, data);
    }
}

void writePort(unique_ptr<Port>& port, BufferData const& data) noexcept {
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

void writePort(Port* port, BufferData const& data) noexcept {
    switch (port->GetType()) {
    case tcp:
        write(*static_cast<TcpPort*>(port), data);
        break;
    case serial:
        write(*static_cast<SerialPort*>(port), data);
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

unique_ptr<Port> createTcpPort(string ip, uint16_t port) noexcept {
    return make_unique<TcpPort>(ip, port);
}

unique_ptr<Port> createSerialPort(string dev) noexcept {
    return make_unique<SerialPort>(dev);
}

} // namespace Enum
// enum_type/src/dev_factory.cpp end

#include <algorithm>
#include <random>

namespace enum_type {

const int randomRange12 = 2; // Give me a number between 0 and 2.
const int errorInt = 0;      // Stop every time the number is 0.
int getRandom12() { return static_cast<int>(random()) % randomRange12; }
const int randomRange13 = 2; // Give me a number between 0 and 2.
int getRandom13() { return static_cast<int>(random()) % randomRange13; }

vu32 GetGlobalRandIntVec() {
    static bool setupDone = false;
    static vector<uint32_t> v(100);
    if (setupDone) {
        return v;
    }
    random_device rd;
    mt19937 generator(rd());
    generate(v.begin(), v.end(), [n = 0]() mutable { return n++; });
    shuffle(v.begin(), v.end(), generator);
    setupDone = true;
    return v;
}

vup EnumPortsInitRandom(vu32& v) {
    using namespace Enum;
    using Ports = vector<unique_ptr<Port> >;

    Ports ports(100);
    for (uint32_t i = 0; i < 50; ++i) {
        ports[v[i]] = createTcpPort("localhost", 2404);
    }
    for (uint32_t i = 50; i < 100; ++i) {
        ports[v[i]] = createSerialPort("/dev/ttyUSB0");
    }

    return ports;
}

vb GetGlobalRandBoolVec() {
    static bool randomDone = false;
    static std::vector<bool> bools(100);

    if (randomDone) {
        return bools;
    }
    auto v = GetGlobalRandIntVec();

    for (uint32_t i = 0; i < 50; ++i) {
        bools[v[i]] = true;
    }
    for (uint32_t i = 51; i < 100; ++i) {
        bools[v[i]] = false;
    }

    randomDone = true;
    return bools;
}

std::size_t GetNextGlobalIndex() {
    static std::size_t it = 0;
    return (++it == 100 ? it = 1 : it);
}

void emptyFn(){};

void emptyFnInt() {
    int x = 1;
    escape(&x);
};

} // namespace enum_type