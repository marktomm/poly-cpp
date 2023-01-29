#include "dev_impl.h"

#include <iostream>

namespace Oop {

std::string TcpPort::GetIp() const noexcept { return ip_; }
uint16_t TcpPort::GetPort() const noexcept { return port_; }

std::string SerialPort::GetDev() const noexcept { return dev_; }

void TcpPort::read(std::string&) noexcept {}

void TcpPort::write(BufferData const& data) noexcept { buf_ += data; }

void TcpPort::stat() const noexcept
{
    using namespace std;
    cout << "tcp port stats\n";
}

void SerialPort::read(std::string&) noexcept {}

void SerialPort::write(BufferData const& data) noexcept { buf_ += data; }

void SerialPort::stat() const noexcept
{
    using namespace std;
    cout << "serial port stats\n";
}

} // namespace Oop