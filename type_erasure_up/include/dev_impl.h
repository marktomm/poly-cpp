#ifndef _TYPE_ERASURE_DEV_IMPL_H_
#define _TYPE_ERASURE_DEV_IMPL_H_

#include "types.h"

#include <memory>
#include <string>

#include <cstdint>

namespace type_erasure_up {

class TcpPort {
public:
    explicit TcpPort(std::string ip, uint16_t pn) noexcept: ip_{ip},
                                                            port_{pn},
                                                            buf_{} {}
    ~TcpPort() = default;

    void Read(BufferData&) const noexcept;
    void Write(BufferData const&) noexcept;

private:
    std::string ip_;
    uint16_t port_;
    MutableBuffer buf_;
};

class SerialPort {
public:
    explicit SerialPort(std::string dev) noexcept: dev_{dev}, buf_{} {}
    ~SerialPort() = default;

    void Read(BufferData&) const noexcept;
    void Write(BufferData const&) noexcept;

private:
    std::string dev_;
    MutableBuffer buf_;
};

} // namespace type_erasure_up

#endif