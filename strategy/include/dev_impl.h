#ifndef _STRATEGY_DEV_IMPL_H_
#define _STRATEGY_DEV_IMPL_H_

#include "dev_base.h"
#include "types.h"

#include <cstdint>

namespace strategy {

class TcpPort: public Port {
public:
    explicit TcpPort(std::string ip, uint16_t pn, ReadTcpPortStrategy strategy,
                     WriteTcpPortStrategy wStrat) noexcept: ip_{ip},
                                                            port_{pn},
                                                            strategy_{strategy},
                                                            wStrat_{wStrat},
                                                            buf_{} {}
    ~TcpPort() = default;

    void Read(BufferData&) const noexcept override;
    void Write(BufferData const&) noexcept override;

private:
    std::string ip_;
    uint16_t port_;
    ReadTcpPortStrategy strategy_;
    WriteTcpPortStrategy wStrat_;
    MutableBuffer buf_;
};

class SerialPort: public Port {
public:
    explicit SerialPort(std::string dev, ReadSerialPortStrategy strategy,
                        WriteSerialPortStrategy wStrat) noexcept
        : dev_{dev},
          strategy_{strategy},
          wStrat_{wStrat},
          buf_{} {}
    ~SerialPort() = default;

    void Read(BufferData&) const noexcept override;
    void Write(BufferData const&) noexcept override;

private:
    std::string dev_;
    ReadSerialPortStrategy strategy_;
    WriteSerialPortStrategy wStrat_;
    MutableBuffer buf_;
};

} // namespace strategy

#endif