#include "dev_impl.h"

std::string TcpPort::GetIp() const { return ip_; }
uint16_t TcpPort::GetPort() const { return port_; }

std::string SerialPort::GetDev() const { return dev_; }