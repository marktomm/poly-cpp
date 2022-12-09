#ifndef _STRATEGY_DEV_IMPL_H_
#define _STRATEGY_DEV_IMPL_H_

#include "dev_base.h"

#include <cstdint>

class TcpPort: public Port
{
public:
    explicit TcpPort(std::string ip, uint16_t pn, StatTcpPortStrategy strategy)
        : ip_{ip}, port_{pn}, strategy_{strategy}
    {
    }
    ~TcpPort() = default;

    void read(std::string&) override;
    void write(std::string const&) override;
    void stat() const override;

    std::string GetIp() const;
    uint16_t GetPort() const;

private:
    std::string ip_;
    uint16_t port_;
    StatTcpPortStrategy strategy_;
};

class SerialPort: public Port
{
public:
    explicit SerialPort(std::string dev, StatSerialPortStrategy strategy)
        : dev_{dev}, strategy_{strategy}
    {
    }
    ~SerialPort() = default;

    void read(std::string&) override;
    void write(std::string const&) override;
    void stat() const override;

    std::string GetDev() const;

private:
    std::string dev_;
    StatSerialPortStrategy strategy_;
};

#endif