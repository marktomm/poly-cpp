#include "dev_ctx.h"
#include "dev_algo.h"
#include "types.h"
#include <vector>

namespace VariantT {

void readPorts(std::vector<Port> const& ports, ReadData& output) noexcept {
    for (auto const& p : ports) {
        std::visit(Read{}, p, output);
    }
}

void writePorts(std::vector<Port>& ports, WriteData const& data) noexcept {
    for (auto& p : ports) {
        std::visit(Write{}, p, data);
    }
}

} // namespace VariantT