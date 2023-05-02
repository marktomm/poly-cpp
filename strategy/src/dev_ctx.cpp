#include "dev_ctx.h"

namespace strategy {

void readPorts(std::vector<std::unique_ptr<Port> > const& ports,
               BufferData& output) noexcept {
    for (auto const& p : ports) {
        p->Read(output);
    }
}

void writePorts(std::vector<std::unique_ptr<Port> > const& ports,
                BufferData const& data) noexcept {
    for (auto const& p : ports) {
        p->Write(data);
    }
}

} // namespace strategy