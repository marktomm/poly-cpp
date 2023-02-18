#include "dev_ctx.h"
#include "dev_algo.h"
#include <vector>

namespace VariantT {

void statPorts(std::vector<Port> const& ports) noexcept {
    for (auto const& p : ports) {
        std::visit(Stat{}, p);
    }
}

void writePorts(std::vector<Port>& ports, WriteData const& data) noexcept {
    for (auto& p : ports) {
        std::visit(Write{}, p, data);
    }
}

} // namespace VariantT