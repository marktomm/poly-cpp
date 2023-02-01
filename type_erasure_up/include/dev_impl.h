#ifndef _TYPE_ERASURE_DEV_IMPL_H_
#define _TYPE_ERASURE_DEV_IMPL_H_

#include "types.h"

#include <memory>
#include <string>

#include <cstdint>

namespace TypeErasureUp {

class TcpPort
{
public:
    explicit TcpPort(std::string ip, uint16_t pn) noexcept: ip_{ip},
                                                            port_{pn},
                                                            buf_{}
    {
    }
    ~TcpPort() = default;

    std::string GetIp() const noexcept;
    uint16_t GetPort() const noexcept;
    void Write(BufferData const&) noexcept;

private:
    std::string ip_;
    uint16_t port_;
    MutableBuffer buf_;
};

class SerialPort
{
public:
    explicit SerialPort(std::string dev) noexcept: dev_{dev}, buf_{} {}
    ~SerialPort() = default;

    std::string GetDev() const noexcept;
    void Write(BufferData const&) noexcept;

private:
    std::string dev_;
    MutableBuffer buf_;
};

} // namespace TypeErasureUp

#endif