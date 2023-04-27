#ifndef _DEV_IMPL_H_
#define _DEV_IMPL_H_

#include "dev_base.h"
#include "types.h"

#include <string>

#include <cstdint>

namespace Enum {

class TcpPort final: public Port {
public:
    explicit TcpPort(std::string ip, uint16_t pn) noexcept: Port{tcp},
                                                            ip_{ip},
                                                            port_{pn},
                                                            buf_{} {}
    ~TcpPort() = default;

    void Read(BufferData&) const noexcept;
    void Write(BufferData const&) noexcept;

private:
    std::string ip_; // unused
    uint16_t port_;  // unused
    MutableBuffer buf_;
};

class SerialPort final: public Port {
public:
    explicit SerialPort(std::string dev) noexcept: Port{serial},
                                                   dev_{dev},
                                                   buf_{} {}
    ~SerialPort() = default;

    void Read(BufferData&) const noexcept;
    void Write(BufferData const&) noexcept;

private:
    std::string dev_; // unused
    MutableBuffer buf_;
};

} // namespace Enum

#endif