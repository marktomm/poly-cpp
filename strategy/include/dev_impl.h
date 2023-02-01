#ifndef _STRATEGY_DEV_IMPL_H_
#define _STRATEGY_DEV_IMPL_H_

#include "dev_base.h"
#include "types.h"

#include <cstdint>

class TcpPort: public Port
{
public:
    explicit TcpPort(std::string ip, uint16_t pn, StatTcpPortStrategy strategy,
                     WriteTcpPortStrategy wStrat)
        : ip_{ip}, port_{pn}, strategy_{strategy}, wStrat_{wStrat}
    {
    }
    ~TcpPort() = default;

    void read(std::string&) override;
    void write(BufferData const&) override;
    void stat() const override;

    std::string GetIp() const;
    uint16_t GetPort() const;

private:
    std::string ip_;
    uint16_t port_;
    StatTcpPortStrategy strategy_;
    WriteTcpPortStrategy wStrat_;
    MutableBuffer buf_;
};

class SerialPort: public Port
{
public:
    explicit SerialPort(std::string dev, StatSerialPortStrategy strategy,
                        WriteSerialPortStrategy wStrat)
        : dev_{dev}, strategy_{strategy}, wStrat_{wStrat}
    {
    }
    ~SerialPort() = default;

    void read(std::string&) override;
    void write(BufferData const&) override;
    void stat() const override;

    std::string GetDev() const;

private:
    std::string dev_;
    StatSerialPortStrategy strategy_;
    WriteSerialPortStrategy wStrat_;
    MutableBuffer buf_;
};

#endif