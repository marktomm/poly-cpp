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

static void escape(void* p) { asm volatile("" : : "g"(p) : "memory"); }

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

vup OopPortsInitRandom(vu32& v) {
    using namespace oop;
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

} // namespace oop