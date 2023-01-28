
#include "dev_algo.h"

#include <iostream>

namespace Enum {

void read(TcpPort&, std::string&) {}
void write(TcpPort& port, BufferData const& data) { port.Write(data); }
void stat(TcpPort const&)
{
    using namespace std;
    cout << "tcp port stats\n";
}

void read(SerialPort&, std::string&) {}
void write(SerialPort& port, BufferData const& data) { port.Write(data); }
void stat(SerialPort const&)
{
    using namespace std;
    cout << "serial port stats\n";
}

} // namespace Enum