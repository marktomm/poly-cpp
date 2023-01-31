#include "dev_algo.h"
#include "dev_ctx.h"
#include "dev_factory.h"

int main()
{
    using Ports = std::vector<std::unique_ptr<Port> >;

    Ports ports;
    ports.push_back(
        CreateTcpPort("localhost", 2404, SyslogStatTcpPortStrategy{}));
    ports.push_back(
        CreateSerialPort("/dev/ttyUSB0", SyslogStatSerialPortStrategy{}));
    statPorts(ports);

    return 0;
}