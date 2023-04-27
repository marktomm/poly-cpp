#include "dev_ctx.h"
#include "dev_algo.h"

namespace Enum {

void readPorts(std::vector<std::unique_ptr<Port> > const& ports,
               BufferData& output) noexcept {
    for (auto const& p : ports) {
        readPort(p, output);
    }
}

void readPort(std::unique_ptr<Port> const& port, BufferData& output) noexcept {
    switch (port->GetType()) {
    case tcp:
        read(*static_cast<TcpPort const*>(port.get()), output);
        break;
    case serial:
        read(*static_cast<SerialPort const*>(port.get()), output);
        break;
    default:
        break;
    }
}

void writePorts(std::vector<std::unique_ptr<Port> >& ports,
                BufferData const& data) noexcept {
    for (auto& p : ports) {
        writePort(p, data);
    }
}

void writePort(std::unique_ptr<Port>& port, BufferData const& data) noexcept {
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