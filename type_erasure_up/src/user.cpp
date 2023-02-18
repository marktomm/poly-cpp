#include "dev_ctx.h"
#include "dev_factory.h"

int main() {
    using namespace TypeErasureUp;
    using Ports = std::vector<statable>;

    Ports ports;
    ports.emplace_back(createTcpPort("localhost", 2404));
    ports.emplace_back(createSerialPort("/dev/ttyUSB0"));
    statPorts(ports);

    return 0;
}