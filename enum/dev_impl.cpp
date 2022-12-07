#include "dev_impl.h"

#include <cstdint>

std::string TcpPort::GetIp() { return ip_; }
uint16_t TcpPort::GetPort() { return port_; }

void read(TcpPort&, std::string&) {}
void write(TcpPort&, std::string const&) {}
void stat(TcpPort const&)
{
    using namespace std;
    cout << "tcp port stats\n";
}

std::string SerialPort::GetDev() { return dev_; }

void read(SerialPort&, std::string&) {}
void write(SerialPort&, std::string const&) {}
void stat(SerialPort const&)
{
    using namespace std;
    cout << "serial port stats\n";
}