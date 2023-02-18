#ifndef _STRATEGY_DEV_IMPL_H_
#define _STRATEGY_DEV_IMPL_H_

#include "dev_base.h"
#include "types.h"

#include <cstdint>

namespace Strategy {

class TcpPort: public Port {
public:
    explicit TcpPort(std::string ip, uint16_t pn, StatTcpPortStrategy strategy,
                     WriteTcpPortStrategy wStrat) noexcept: ip_{ip},
                                                            port_{pn},
                                                            strategy_{strategy},
                                                            wStrat_{wStrat},
                                                            buf_{} {}
    ~TcpPort() = default;

    void read(std::string&) noexcept override;
    void write(BufferData const&) noexcept override;
    void stat() const noexcept override;

    std::string GetIp() const noexcept;
    uint16_t GetPort() const noexcept;

private:
    std::string ip_;
    uint16_t port_;
    StatTcpPortStrategy strategy_;
    WriteTcpPortStrategy wStrat_;
    MutableBuffer buf_;
};

class SerialPort: public Port {
public:
    explicit SerialPort(std::string dev, StatSerialPortStrategy strategy,
                        WriteSerialPortStrategy wStrat) noexcept
        : dev_{dev},
          strategy_{strategy},
          wStrat_{wStrat},
          buf_{} {}
    ~SerialPort() = default;

    void read(std::string&) noexcept override;
    void write(BufferData const&) noexcept override;
    void stat() const noexcept override;

    std::string GetDev() const noexcept;

private:
    std::string dev_;
    StatSerialPortStrategy strategy_;
    WriteSerialPortStrategy wStrat_;
    MutableBuffer buf_;
};

} // namespace Strategy

#endif