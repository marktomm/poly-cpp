#ifndef _VARIANT_DEV_IMPL_H_
#define _VARIANT_DEV_IMPL_H_

#include "types.h"

#include <string>

#include <cstdint>

namespace VariantT {

class TcpPort
{
public:
    explicit TcpPort(std::string ip, uint16_t pn) : ip_{ip}, port_{pn}, buf_{}
    {
    }
    ~TcpPort() = default;

    std::string GetIp() const;
    uint16_t GetPort() const;
    void Write(BufferData const&);

private:
    std::string ip_;
    uint16_t port_;
    MutableBuffer buf_;
};

class SerialPort
{
public:
    explicit SerialPort(std::string dev) : dev_{dev}, buf_{} {}
    ~SerialPort() = default;

    std::string GetDev() const;
    void Write(BufferData const&);

private:
    std::string dev_;
    MutableBuffer buf_;
};

} // namespace VariantT

#endif