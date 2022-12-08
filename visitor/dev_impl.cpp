#include "dev_impl.h"

#include <iostream>

std::string TcpPort::GetIp() const { return ip_; }
uint16_t TcpPort::GetPort() const { return port_; }

std::string SerialPort::GetDev() const { return dev_; }

void Stat::visit(TcpPort const& p) const
{
    using namespace std;
    cout << "tcp port stats\n";
}

void Stat::visit(SerialPort const& p) const
{
    using namespace std;
    cout << "serial port stats\n";
}

void TcpPort::accept(Visitor const& v) { v.visit(*this); }

void SerialPort::accept(Visitor const& v) { v.visit(*this); }