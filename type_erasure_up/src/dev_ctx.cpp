#include "dev_ctx.h"
#include "types.h"

namespace TypeErasureUp {

void stat(std::vector<statable> const& doc) noexcept {
    for (auto const& it : doc) {
        stat(it);
    }
}

void write(std::vector<statable>& doc, BufferData const& data) noexcept {
    for (auto& it : doc) {
        write(it, data);
    }
}

void statPorts(std::vector<statable> const& ports) noexcept { stat(ports); }

void writePorts(std::vector<statable>& ports, BufferData const& data) noexcept {
    write(ports, data);
}

void swap(statable& a, statable& b) { a.swap(b); }

} // namespace TypeErasureUp