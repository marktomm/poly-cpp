#include "dev_ctx.h"
#include "types.h"

namespace type_erasure_up {

void read(std::vector<Readable> const& doc, BufferData& output) noexcept {
    for (auto const& it : doc) {
        read(it, output);
    }
}

void write(std::vector<Readable>& doc, BufferData const& data) noexcept {
    for (auto& it : doc) {
        write(it, data);
    }
}

void readPorts(std::vector<Readable> const& ports,
               BufferData& output) noexcept {
    read(ports, output);
}

void writePorts(std::vector<Readable>& ports, BufferData const& data) noexcept {
    write(ports, data);
}

void swap(Readable& a, Readable& b) { a.swap(b); }

} // namespace type_erasure_up