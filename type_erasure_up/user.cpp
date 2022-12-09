#include "dev_algo.h"
#include "dev_ctx.h"

int main()
{
    using Ports = std::vector<statable>;

    Ports ports;
    ports.emplace_back(TcpPort{"localhost", 2404});
    ports.emplace_back(SerialPort{"/dev/ttyUSB0"});
    statPorts(ports);

    return 0;
}