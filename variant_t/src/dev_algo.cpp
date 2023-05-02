#include "dev_algo.h"
#include "dev_impl.h"

#include <iostream>

namespace variant_t {

void Read::operator()(TcpPort const& p, BufferData& output) const noexcept {
    p.Read(output);
}

void Read::operator()(SerialPort const& p, BufferData& output) const noexcept {
    p.Read(output);
}

void Write::operator()(TcpPort& p, BufferData const& data) const noexcept {
    p.Write(data);
}

void Write::operator()(SerialPort& p, BufferData const& data) const noexcept {
    p.Write(data);
}

} // namespace variant_t