#include "dev_impl.h"

std::string TcpPort::GetIp() const { return ip_; }
uint16_t TcpPort::GetPort() const { return port_; }

void TcpPort::Write(const BufferData& data) { buf_ += data; }

std::string SerialPort::GetDev() const { return dev_; }

void SerialPort::Write(const BufferData& data) { buf_ += data; }