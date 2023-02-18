#include "dev_algo.h"

#include <iostream>

namespace Visit {

void Stat::visit(TcpPort const&) const noexcept {
    using namespace std;
    cout << "tcp port stats\n";
}

void Stat::visit(SerialPort const& p) const noexcept {
    using namespace std;
    cout << "serial port stats " << p.GetDev() << "\n";
}

void Stat::visit(TcpPort&) const noexcept {
    using namespace std;
    // unused
}

void Stat::visit(SerialPort&) const noexcept {
    using namespace std;
    // unused
}

void Write::visit(TcpPort const&) const noexcept {
    using namespace std;
    // unused
}

void Write::visit(SerialPort const&) const noexcept {
    using namespace std;
    // unused
}

void Write::visit(TcpPort& p) const noexcept {
    using namespace std;
    p.Write(data_);
}

void Write::visit(SerialPort& p) const noexcept {
    using namespace std;
    p.Write(data_);
}

} // namespace Visit