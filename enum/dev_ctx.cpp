#include "dev_ctx.h"
#include "dev_algo.h"

void statPorts(std::vector<std::unique_ptr<Port> > const& ports)
{
    for (auto const& p : ports) {
        statPort(p);
    }
}

void statPort(std::unique_ptr<Port> const& port)
{
    switch (port->GetType()) {
    case tcp:
        stat(*static_cast<TcpPort const*>(port.get()));
        break;
    case serial:
        stat(*static_cast<SerialPort const*>(port.get()));
        break;
    default:
        break;
    }
}