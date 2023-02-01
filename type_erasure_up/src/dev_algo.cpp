#include "dev_algo.h"

#include <iostream>

void read(TcpPort&, std::string&) {}
void write(TcpPort& p, BufferData const& data) { p.Write(data); }
void stat(TcpPort const& port)
{
    using namespace std;
    cout << "tcp port stats " << port.GetIp() << ":" << port.GetPort() << "\n";
}

void read(SerialPort&, std::string&) {}
void write(SerialPort& p, BufferData const& data) { p.Write(data); }
void stat(SerialPort const& port)
{
    using namespace std;
    cout << "serial port stats " << port.GetDev() << "\n";
}