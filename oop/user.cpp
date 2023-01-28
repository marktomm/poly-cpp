#include "dev_ctx.h"
#include "dev_factory.h"

int main()
{
    using namespace Oop;
    using Ports = std::vector<std::unique_ptr<Port> >;

    Ports ports;
    ports.push_back(CreateTcpPort("localhost", 2404));
    ports.push_back(CreateSerialPort("/dev/ttyUSB0"));
    statPorts(ports);

    return 0;
}