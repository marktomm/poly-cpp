#include "dev_impl.h"

#include "dev_ctx.h"

int main()
{
    using Ports = std::vector<std::unique_ptr<Port> >;

    Ports ports;
    ports.push_back(std::make_unique<TcpPort>("localhost", 2404));
    ports.push_back(std::make_unique<SerialPort>("/dev/ttyUSB0"));
    statPorts(ports);

    return 0;
}