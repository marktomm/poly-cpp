#include "dev_factory.h"
#include "dev_algo.h"
#include "dev_impl.h"

#include <memory>

statable CreateTcpPort(std::string ip, uint16_t port)
{
    return TcpPort(ip, port);
}

statable CreateSerialPort(std::string dev) { return SerialPort(dev); }
