#include "dev_ctx.h"

int main()
{
    using Ports = std::vector<Port>;

    Ports ports;
    ports.push_back(TcpPort{"localhost", 2404});
    ports.push_back(SerialPort{"/dev/ttyUSB0"});
    statPorts(ports);

    return 0;
}