#ifndef _OOP_DEV_IMPL_H_
#define _OOP_DEV_IMPL_H_

#include "dev_base.h"

#include <cstdint>

namespace Oop {

class TcpPort final: public Port {
public:
    explicit TcpPort(std::string ip, uint16_t pn) noexcept: ip_{ip},
                                                            port_{pn},
                                                            buf_{} {}
    ~TcpPort() = default;

    void Read(BufferData&) const noexcept override;
    void Write(BufferData const&) noexcept override;

    std::string GetIp() const noexcept;
    uint16_t GetPort() const noexcept;

private:
    std::string ip_;
    uint16_t port_;
    MutableBuffer buf_;
};

class SerialPort final: public Port {
public:
    explicit SerialPort(std::string dev) noexcept: dev_{dev}, buf_{} {}
    ~SerialPort() = default;

    void Read(BufferData&) const noexcept override;
    void Write(BufferData const&) noexcept override;

    std::string GetDev() const noexcept;

private:
    std::string dev_;
    MutableBuffer buf_;
};

} // namespace Oop

#endif