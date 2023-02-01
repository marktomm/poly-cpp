#include "dev_algo.h"
#include "dev_impl.h"

#include <iostream>

namespace VariantT {

void Stat::operator()(TcpPort const& p) const noexcept
{
    using namespace std;
    cout << "tcp port stats\n";
}

void Stat::operator()(SerialPort const& p) const noexcept
{
    using namespace std;
    cout << "serial port stats " << p.GetDev() << "\n";
}

void Write::operator()(TcpPort& p, BufferData const& data) const noexcept
{
    p.Write(data);
}

void Write::operator()(SerialPort& p, BufferData const& data) const noexcept
{
    p.Write(data);
}

} // namespace VariantT