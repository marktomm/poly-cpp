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

void Stat::visit(TcpPort& p) const noexcept
{
    using namespace std;
    throw std::runtime_error("do not read from non const TcpPort");
}

void Stat::visit(SerialPort& p) const noexcept
{
    using namespace std;
    throw std::runtime_error("do not read from non const Serial");
}

void Write::visit(TcpPort const& p) const noexcept
{
    using namespace std;
    throw std::runtime_error("cannot write to const TcpPort");
    // p.Write(data_);
}

void Write::visit(SerialPort const& p) const noexcept
{
    using namespace std;
    throw std::runtime_error("cannot write to const SerialPort");
    // p.Write(data_);
}

void Write::visit(TcpPort& p) const noexcept
{
    using namespace std;
    p.Write(data_);
}

void Write::visit(SerialPort& p) const noexcept
{
    using namespace std;
    p.Write(data_);
}

} // namespace Visit