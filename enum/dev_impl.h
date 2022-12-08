#ifndef _DEV_IMPL_H_
#define _DEV_IMPL_H_

#include "dev_base.h"

#include <string>

#include <cstdint>

class TcpPort: public Port
{
public:
    explicit TcpPort(std::string ip, uint16_t pn)
        : Port{tcp}, ip_(ip), port_{pn}
    {
    }
    ~TcpPort() = default;

    std::string GetIp() const;
    uint16_t GetPort() const;

private:
    std::string ip_;
    uint16_t port_;
};

class SerialPort: public Port
{
public:
    explicit SerialPort(std::string dev) : Port{serial}, dev_{dev} {}
    ~SerialPort() = default;

    std::string GetDev() const;

private:
    std::string dev_;
};

#endif