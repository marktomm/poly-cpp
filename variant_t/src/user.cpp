#include "dev_ctx.h"
#include "types.h"

int main()
{
    using Ports = std::vector<Port>;

    Ports ports;
    ports.push_back(TcpPort{"localhost", 2404});
    ports.push_back(SerialPort{"/dev/ttyUSB0"});
    statPorts(ports);
    writePorts(ports, BufferData{10});

    return 0;
}