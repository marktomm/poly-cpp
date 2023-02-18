#include "dev_ctx.h"
#include "dev_algo.h"

namespace Visit {

void statPorts(std::vector<std::unique_ptr<Port> > const& ports) noexcept {
    for (auto const& p : ports) {
        p->accept(Stat{});
    }
}

void writePorts(std::vector<std::unique_ptr<Port> >& ports,
                BufferData const& data) noexcept {
    for (auto& p : ports) {
        p->accept(Write{data});
    }
}

} // namespace Visit