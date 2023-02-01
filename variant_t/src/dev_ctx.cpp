#include "dev_ctx.h"
#include "dev_algo.h"
#include <vector>

void statPorts(std::vector<Port> const& ports)
{
    for (auto const& p : ports) {
        std::visit(Stat{}, p);
    }
}

void writePorts(std::vector<Port>& ports, WriteData const& data)
{
    for (auto& p : ports) {
        std::visit(Write{}, p, data);
    }
}