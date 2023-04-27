#include "dev_algo.h"

#include <iostream>

namespace Visit {

void Read::visit(TcpPort const& p) const noexcept { p.Read(data_); }

void Read::visit(SerialPort const& p) const noexcept { p.Read(data_); }

void Read::visit(TcpPort&) const noexcept {
    // unused
}

void Read::visit(SerialPort&) const noexcept {
    // unused
}

void Write::visit(TcpPort const&) const noexcept {
    // unused
}

void Write::visit(SerialPort const&) const noexcept {
    // unused
}

void Write::visit(TcpPort& p) const noexcept { p.Write(data_); }

void Write::visit(SerialPort& p) const noexcept { p.Write(data_); }

} // namespace Visit