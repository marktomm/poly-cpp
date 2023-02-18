#include "dev_ctx.h"

namespace Strategy {

void statPorts(std::vector<std::unique_ptr<Port> > const& ports) noexcept {
    for (auto const& p : ports) {
        p->stat();
    }
}

void writePorts(std::vector<std::unique_ptr<Port> > const& ports,
                BufferData const& data) noexcept {
    for (auto const& p : ports) {
        p->write(data);
    }
}

} // namespace Strategy