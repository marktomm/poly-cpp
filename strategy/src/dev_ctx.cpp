#include "dev_ctx.h"

void statPorts(std::vector<std::unique_ptr<Port> > const& ports)
{
    for (auto const& p : ports) {
        p->stat();
    }
}

void writePorts(std::vector<std::unique_ptr<Port> > const& ports,
                BufferData const& data)
{
    for (auto const& p : ports) {
        p->write(data);
    }
}