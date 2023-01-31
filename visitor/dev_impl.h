#ifndef _VISITOR_DEV_IMPL_H_
#define _VISITOR_DEV_IMPL_H_

#include "types.h"
#include "dev_base.h"

#include <cstdint>

namespace Visit {

class TcpPort final: public Port
{
public:
    explicit TcpPort(std::string ip, uint16_t pn) : ip_{ip}, port_{pn}, buf_{}
    {
    }
    ~TcpPort() = default;

    void accept(Visitor const&) const noexcept override;

    std::string GetIp() const noexcept;
    uint16_t GetPort() const noexcept;
    void Write(BufferData const&) const noexcept;

private:
    std::string ip_;
    uint16_t port_;
    mutable MutableBuffer buf_;
};

class SerialPort final: public Port
{
public:
    explicit SerialPort(std::string dev) : dev_{dev}, buf_{} {}
    ~SerialPort() = default;

    void accept(Visitor const&) const noexcept override;

    std::string GetDev() const noexcept;
    void Write(BufferData const&) const noexcept;

private:
    std::string dev_;
    mutable MutableBuffer buf_;
};

class Port::Visitor
{
public:
    virtual ~Visitor() = default;

    virtual void visit(TcpPort const&) const noexcept = 0;
    virtual void visit(SerialPort const&) const noexcept = 0;
};

} // namespace Visit

#endif