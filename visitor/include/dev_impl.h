#ifndef _VISITOR_DEV_IMPL_H_
#define _VISITOR_DEV_IMPL_H_

#include "dev_base.h"
#include "types.h"

#include <cstdint>

namespace Visit {

class TcpPort final: public Port {
public:
    explicit TcpPort(std::string ip, uint16_t pn) noexcept: ip_{ip},
                                                            port_{pn},
                                                            buf_{} {}
    ~TcpPort() = default;

    void accept(Visitor const&) const noexcept override;
    void accept(Visitor const&) noexcept override;

    std::string GetIp() const noexcept;
    uint16_t GetPort() const noexcept;
    void Write(BufferData const&) noexcept;

private:
    std::string ip_;
    uint16_t port_;
    MutableBuffer buf_;
};

class SerialPort final: public Port {
public:
    explicit SerialPort(std::string dev) noexcept: dev_{dev}, buf_{} {}
    ~SerialPort() = default;

    void accept(Visitor const&) const noexcept override;
    void accept(Visitor const&) noexcept override;

    std::string GetDev() const noexcept;
    void Write(BufferData const&) noexcept;

private:
    std::string dev_;
    MutableBuffer buf_;
};

class Port::Visitor {
public:
    virtual ~Visitor() = default;

    virtual void visit(TcpPort const&) const noexcept = 0;
    virtual void visit(SerialPort const&) const noexcept = 0;

    virtual void visit(TcpPort&) const noexcept = 0;
    virtual void visit(SerialPort&) const noexcept = 0;
};

} // namespace Visit

#endif