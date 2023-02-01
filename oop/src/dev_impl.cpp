#include "dev_impl.h"

#include <iostream>

namespace Oop {

std::string TcpPort::GetIp() const noexcept { return ip_; }
uint16_t TcpPort::GetPort() const noexcept { return port_; }

std::string SerialPort::GetDev() const noexcept { return dev_; }

void TcpPort::Read(std::string&) noexcept {}

void TcpPort::Write(BufferData const& data) noexcept { buf_ += data; }

void TcpPort::Stat() const noexcept
{
    using namespace std;
    cout << "tcp port stats\n";
}

void SerialPort::Read(std::string&) noexcept {}

void SerialPort::Write(BufferData const& data) noexcept { buf_ += data; }

void SerialPort::Stat() const noexcept
{
    using namespace std;
    cout << "serial port stats\n";
}

} // namespace Oop