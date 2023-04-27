#include "dev_ctx.h"
#include "types.h"

int main() {
    using namespace VariantT;
    using Ports = std::vector<Port>;

    Ports ports;
    ports.push_back(TcpPort{"localhost", 2404});
    ports.push_back(SerialPort{"/dev/ttyUSB0"});
    ReadData data;
    readPorts(ports, data);
    writePorts(ports, BufferData{10});

    return 0;
}