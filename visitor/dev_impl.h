#ifndef _VISITOR_DEV_IMPL_H_
#define _VISITOR_DEV_IMPL_H_

#include "dev_base.h"

#include <cstdint>

class TcpPort: public Port
{
public:
    explicit TcpPort(std::string ip, uint16_t pn) : ip_(ip), port_{pn} {}
    ~TcpPort() = default;

    void accept(Visitor const&) override;

    std::string GetIp() const;
    uint16_t GetPort() const;

private:
    std::string ip_;
    uint16_t port_;
};

class SerialPort: public Port
{
public:
    explicit SerialPort(std::string dev) : dev_{dev} {}
    ~SerialPort() = default;

    void accept(Visitor const&) override;

    std::string GetDev() const;

private:
    std::string dev_;
};

class Stat: public Visitor
{
public:
    void visit(TcpPort const&) const override;
    void visit(SerialPort const&) const override;
};

#endif