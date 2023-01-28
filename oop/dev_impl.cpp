#include "dev_impl.h"

#include <iostream>

namespace Oop {

std::string TcpPort::GetIp() const { return ip_; }
uint16_t TcpPort::GetPort() const { return port_; }

std::string SerialPort::GetDev() const { return dev_; }

void TcpPort::read(std::string&) {}

void TcpPort::write(BufferData const& data) { buf_ += data; }

void TcpPort::stat() const
{
    using namespace std;
    cout << "tcp port stats\n";
}

void SerialPort::read(std::string&) {}

void SerialPort::write(BufferData const& data) { buf_ += data; }

void SerialPort::stat() const
{
    using namespace std;
    cout << "serial port stats\n";
}

} // namespace Oop