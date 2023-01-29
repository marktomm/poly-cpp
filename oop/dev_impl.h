#ifndef _OOP_DEV_IMPL_H_
#define _OOP_DEV_IMPL_H_

#include "dev_base.h"

#include <cstdint>

namespace Oop {

class TcpPort final: public Port
{
public:
    explicit TcpPort(std::string ip, uint16_t pn) : ip_{ip}, port_{pn}, buf_{}
    {
    }
    ~TcpPort() = default;

    void read(std::string&) noexcept override;
    void write(BufferData const&) noexcept override;
    void stat() const noexcept override;

    std::string GetIp() const noexcept;
    uint16_t GetPort() const noexcept;

private:
    std::string ip_;
    uint16_t port_;
    MutableBuffer buf_;
};

class SerialPort final: public Port
{
public:
    explicit SerialPort(std::string dev) : dev_{dev}, buf_{} {}
    ~SerialPort() = default;

    void read(std::string&) noexcept override;
    void write(BufferData const&) noexcept override;
    void stat() const noexcept override;

    std::string GetDev() const noexcept;

private:
    std::string dev_;
    MutableBuffer buf_;
};

} // namespace Oop

#endif