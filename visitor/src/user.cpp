#include "dev_ctx.h"
#include "dev_factory.h"
#include "types.h"

int main() {
    using namespace Visit;
    using Ports = std::vector<std::unique_ptr<Port> >;

    Ports ports;
    ports.push_back(createTcpPort("localhost", 2404));
    ports.push_back(createSerialPort("/dev/ttyUSB0"));
    BufferData data;
    readPorts(ports, data);

    return 0;
}