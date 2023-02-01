#include "dev_ctx.h"

namespace Oop {

void statPorts(std::vector<std::unique_ptr<Port> > const& ports) noexcept
{
    for (auto const& p : ports) {
        p->Stat();
    }
}

void writePorts(std::vector<std::unique_ptr<Port> >& ports,
                BufferData const& data) noexcept
{
    for (auto const& p : ports) {
        p->Write(data);
    }
}

} // namespace Oop