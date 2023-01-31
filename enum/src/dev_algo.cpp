
#include "dev_algo.h"

#include <iostream>

namespace Enum {

void read(TcpPort&, std::string&) noexcept {}
void write(TcpPort& port, BufferData const& data) noexcept { port.Write(data); }
void stat(TcpPort const&) noexcept
{
    using namespace std;
    cout << "tcp port stats\n";
}

void read(SerialPort&, std::string&) noexcept {}
void write(SerialPort& port, BufferData const& data) noexcept
{
    port.Write(data);
}
void stat(SerialPort const&) noexcept
{
    using namespace std;
    cout << "serial port stats\n";
}

} // namespace Enum