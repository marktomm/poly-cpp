#include "dev_ctx.h"
#include "dev_algo.h"

void statPorts(std::vector<Port> const& ports)
{
    for (auto const& p : ports) {
        std::visit(Stat{}, p);
    }
}