#include "dev_ctx.h"
#include "dev_factory.h"

int main()
{
    using Ports = std::vector<statable>;

    Ports ports;
    ports.emplace_back(CreateTcpPort("localhost", 2404));
    ports.emplace_back(CreateSerialPort("/dev/ttyUSB0"));
    statPorts(ports);

    return 0;
}