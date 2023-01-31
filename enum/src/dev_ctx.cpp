#include "dev_ctx.h"
#include "dev_algo.h"

namespace Enum {

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

void writePorts(std::vector<std::unique_ptr<Port> >& ports,
                BufferData const& data)
{
    for (auto& p : ports) {
        writePort(p, data);
    }
}

void writePort(std::unique_ptr<Port>& port, BufferData const& data)
{
    switch (port->GetType()) {
    case tcp:
        write(*static_cast<TcpPort*>(port.get()), data);
        break;
    case serial:
        write(*static_cast<SerialPort*>(port.get()), data);
        break;
    default:
        break;
    }
}

} // namespace Enum