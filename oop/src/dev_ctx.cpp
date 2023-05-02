#include "dev_ctx.h"

namespace oop {

void readPorts(std::vector<std::unique_ptr<Port> > const& ports,
               BufferData& data) noexcept {
    for (auto const& p : ports) {
        p->Read(data);
    }
}

void writePorts(std::vector<std::unique_ptr<Port> >& ports,
                BufferData const& data) noexcept {
    for (auto const& p : ports) {
        p->Write(data);
    }
}

} // namespace oop