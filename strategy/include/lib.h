// ./common/include/lib.h
#ifndef _COMMON_TYPES_H_
#define _COMMON_TYPES_H_

#include <cstdint>

using MutableBuffer = uint32_t;
using BufferData = uint32_t;

#endif
// ./common/include/lib.h end
// strategy/include/dev_base.h
#ifndef _STRATEGY_DEV_BASE_H_
#define _STRATEGY_DEV_BASE_H_

#include <functional>
#include <string>

namespace strategy {

class TcpPort;
class SerialPort;

using ReadTcpPortStrategy = std::function<void(TcpPort const&, BufferData&)>;
using ReadSerialPortStrategy =
    std::function<void(SerialPort const&, BufferData&)>;

using WriteTcpPortStrategy = std::function<void(TcpPort&, BufferData const&)>;
using WriteSerialPortStrategy =
    std::function<void(SerialPort&, BufferData const&)>;

class Port {
public:
    Port() = default;
    virtual ~Port() = default;

    virtual void Read(BufferData&) const noexcept = 0;
    virtual void Write(BufferData const&) noexcept = 0;
};

} // namespace strategy

#endif
// strategy/include/dev_base.h end
// strategy/include/dev_impl.h
#ifndef _STRATEGY_DEV_IMPL_H_
#define _STRATEGY_DEV_IMPL_H_

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
// strategy/include/dev_impl.h end
// strategy/include/dev_algo.h
#ifndef _STRATEGY_DEV_ALGO_H_
#define _STRATEGY_DEV_ALGO_H_

namespace strategy {

class SyslogReadTcpPortStrategy {
public:
    void operator()(TcpPort const&, BufferData&) const noexcept;
};

class SyslogReadSerialPortStrategy {
public:
    void operator()(SerialPort const&, BufferData&) const noexcept;
};

class SyncWriteTcpPortStrategy {
public:
    void operator()(TcpPort&, BufferData const&) const noexcept;
};

class SyncWriteSerialPortStrategy {
public:
    void operator()(SerialPort&, BufferData const&) const noexcept;
};

} // namespace strategy

#endif
// strategy/include/dev_algo.h end
// strategy/include/dev_ctx.h
#ifndef _STRATEGY_DEV_EXT_H_
#define _STRATEGY_DEV_EXT_H_

#include <memory>
#include <vector>

namespace strategy {

void readPorts(std::vector<std::unique_ptr<Port> > const&,
               BufferData&) noexcept;

void writePorts(std::vector<std::unique_ptr<Port> > const&,
                BufferData const&) noexcept;

} // namespace strategy

#endif
// strategy/include/dev_ctx.h end
// strategy/include/dev_factory.h
#ifndef _STRATEGY_DEV_FACTORY_H_
#define _STRATEGY_DEV_FACTORY_H_

#include <memory>
#include <string>

#include <cstdint>

namespace strategy {

std::unique_ptr<Port> createTcpPort(std::string ip, uint16_t port,
                                    ReadTcpPortStrategy,
                                    WriteTcpPortStrategy) noexcept;

std::unique_ptr<Port> createSerialPort(std::string dev, ReadSerialPortStrategy,
                                       WriteSerialPortStrategy) noexcept;

} // namespace strategy

#endif
// strategy/include/dev_factory.h end
