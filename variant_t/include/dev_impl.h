#ifndef _VARIANT_DEV_IMPL_H_
#define _VARIANT_DEV_IMPL_H_

#include <string>

#include <cstdint>

class TcpPort
{
public:
    explicit TcpPort(std::string ip, uint16_t pn) : ip_{ip}, port_{pn} {}
    ~TcpPort() = default;

    std::string GetIp() const;
    uint16_t GetPort() const;

private:
    std::string ip_;
    uint16_t port_;
};

class SerialPort
{
public:
    explicit SerialPort(std::string dev) : dev_{dev} {}
    ~SerialPort() = default;

    std::string GetDev() const;

private:
    std::string dev_;
};

#endif