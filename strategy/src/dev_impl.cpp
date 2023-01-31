#include "dev_impl.h"

std::string TcpPort::GetIp() const { return ip_; }
uint16_t TcpPort::GetPort() const { return port_; }

std::string SerialPort::GetDev() const { return dev_; }

void TcpPort::read(std::string&) {}

void TcpPort::write(std::string const&) {}

void TcpPort::stat() const { strategy_(*this); }

void SerialPort::read(std::string&) {}

void SerialPort::write(std::string const&) {}

void SerialPort::stat() const { strategy_(*this); }