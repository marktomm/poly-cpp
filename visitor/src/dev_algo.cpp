#include "dev_algo.h"

#include <iostream>

namespace Visit {

void Stat::visit(TcpPort const& p) const noexcept
{
    using namespace std;
    cout << "tcp port stats\n";
}

void Stat::visit(SerialPort const& p) const noexcept
{
    using namespace std;
    cout << "serial port stats " << p.GetDev() << "\n";
}

void Write::visit(TcpPort const& p) const noexcept
{
    using namespace std;
    p.Write(data_);
}

void Write::visit(SerialPort const& p) const noexcept
{
    using namespace std;
    p.Write(data_);
}

} // namespace Visit