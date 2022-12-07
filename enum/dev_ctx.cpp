#include "dev_ctx.h"
#include "dev_impl.h"

void statPorts(std::vector<std::unique_ptr<Port> > const& shapes)
{
    for (auto const& s : shapes) {
        switch (s->GetType()) {
        case tcp:
            stat(*static_cast<TcpPort const*>(s.get()));
            break;
        case serial:
            stat(*static_cast<SerialPort const*>(s.get()));
            break;
        default:
            break;
        }
    }
}