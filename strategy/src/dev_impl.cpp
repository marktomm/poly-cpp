#include "dev_impl.h"

std::string TcpPort::GetIp() const { return ip_; }
uint16_t TcpPort::GetPort() const { return port_; }

std::string SerialPort::GetDev() const { return dev_; }

void TcpPort::read(std::string&) {}

void TcpPort::write(BufferData const& data) { buf_ += data; }

void TcpPort::stat() const { strategy_(*this); }

void SerialPort::read(std::string&) {}

void SerialPort::write(BufferData const& data) { buf_ += data; }

void SerialPort::stat() const { strategy_(*this); }