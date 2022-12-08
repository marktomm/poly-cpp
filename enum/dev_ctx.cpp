#include "dev_ctx.h"
#include "dev_algo.h"

void statPorts(std::vector<std::unique_ptr<Port> > const& ports)
{
    for (auto const& p : ports) {
        switch (p->GetType()) {
        case tcp:
            stat(*static_cast<TcpPort const*>(p.get()));
            break;
        case serial:
            stat(*static_cast<SerialPort const*>(p.get()));
            break;
        default:
            break;
        }
    }
}