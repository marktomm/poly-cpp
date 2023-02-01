#ifndef _DEV_IMPL_H_
#define _DEV_IMPL_H_

#include "dev_base.h"
#include "types.h"

#include <string>

#include <cstdint>

namespace Enum {

class TcpPort final: public Port
{
public:
    explicit TcpPort(std::string ip, uint16_t pn)
        : Port{tcp}, ip_{ip}, port_{pn}, buf_{}
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

class SerialPort final: public Port
{
public:
    explicit SerialPort(std::string dev) : Port{serial}, dev_{dev}, buf_{} {}
    ~SerialPort() = default;

    std::string GetDev() const noexcept;
    void Write(BufferData const&) noexcept;

private:
    std::string dev_;
    MutableBuffer buf_;
};

} // namespace Enum

#endif