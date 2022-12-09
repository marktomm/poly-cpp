#include "dev_algo.h"

#include <iostream>

void read(TcpPort&, std::string&) {}
void write(TcpPort&, std::string const&) {}
void stat(TcpPort const& port)
{
    using namespace std;
    cout << "tcp port stats " << port.GetIp() << ":" << port.GetPort() << "\n";
}

void read(SerialPort&, std::string&) {}
void write(SerialPort&, std::string const&) {}
void stat(SerialPort const& port)
{
    using namespace std;
    cout << "serial port stats " << port.GetDev() << "\n";
}