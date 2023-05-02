#include "dev_ctx.h"
#include "dev_algo.h"
#include "types.h"

namespace visitor {

void readPorts(std::vector<std::unique_ptr<Port> > const& ports,
               BufferData& output) noexcept {
    for (auto const& p : ports) {
        p->accept(Read{output});
    }
}

void writePorts(std::vector<std::unique_ptr<Port> >& ports,
                BufferData const& data) noexcept {
    for (auto& p : ports) {
        p->accept(Write{data});
    }
}

} // namespace visitor