#include "dev_ctx.h"
#include "dev_algo.h"

void statPorts(std::vector<std::unique_ptr<Port> > const& ports)
{
    for (auto const& p : ports) {
        p->accept(Stat{});
    }
}