#include "dev_ctx.h"
#include "types.h"

namespace TypeErasureUp {

void stat(std::vector<Readable> const& doc) noexcept {
    for (auto const& it : doc) {
        stat(it);
    }
}

void write(std::vector<Readable>& doc, BufferData const& data) noexcept {
    for (auto& it : doc) {
        write(it, data);
    }
}

void statPorts(std::vector<Readable> const& ports) noexcept { stat(ports); }

void writePorts(std::vector<Readable>& ports, BufferData const& data) noexcept {
    write(ports, data);
}

void swap(Readable& a, Readable& b) { a.swap(b); }

} // namespace TypeErasureUp