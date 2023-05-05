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

class Port;
class TcpPort;
class SerialPort;

using ReadBaseStrategy = std::function<void(BufferData&)>;
using WriteBaseStrategy = std::function<void(BufferData const&)>;

class Port {
public:
    Port() = default;
    virtual ~Port() = default;

    virtual void Read(BufferData&) const noexcept = 0;
    virtual void Write(BufferData const&) noexcept = 0;

    virtual void SetReadStrat(ReadBaseStrategy) noexcept = 0;
    virtual void SetWriteStrat(WriteBaseStrategy) noexcept = 0;
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
    explicit TcpPort(std::string ip, uint16_t pn, ReadBaseStrategy strategy,
                     WriteBaseStrategy wStrat) noexcept: ip_{ip},
                                                         port_{pn},
                                                         strategy_{strategy},
                                                         wStrat_{wStrat},
                                                         buf_{} {}
    ~TcpPort() = default;

    void Read(BufferData&) const noexcept override;
    void Write(BufferData const&) noexcept override;

    void SetReadStrat(ReadBaseStrategy) noexcept override;
    void SetWriteStrat(WriteBaseStrategy) noexcept override;

private:
    std::string ip_;
    uint16_t port_;
    ReadBaseStrategy strategy_;
    WriteBaseStrategy wStrat_;
    MutableBuffer buf_;
};

class SerialPort: public Port {
public:
    explicit SerialPort(std::string dev, ReadBaseStrategy strategy,
                        WriteBaseStrategy wStrat) noexcept: dev_{dev},
                                                            strategy_{strategy},
                                                            wStrat_{wStrat},
                                                            buf_{} {}
    ~SerialPort() = default;

    void Read(BufferData&) const noexcept override;
    void Write(BufferData const&) noexcept override;

    void SetReadStrat(ReadBaseStrategy) noexcept override;
    void SetWriteStrat(WriteBaseStrategy) noexcept override;

private:
    std::string dev_;
    ReadBaseStrategy strategy_;
    WriteBaseStrategy wStrat_;
    MutableBuffer buf_;
};

} // namespace strategy

#endif
// strategy/include/dev_impl.h end
// strategy/include/dev_algo.h
#ifndef _STRATEGY_DEV_ALGO_H_
#define _STRATEGY_DEV_ALGO_H_

namespace strategy {

class SyslogReadStrategy {
public:
    void operator()(BufferData&) const noexcept;
};

class SyncWriteStrategy {
public:
    void operator()(BufferData const&) const noexcept;
};

class UnbufferedWriteStrategy {
public:
    void operator()(BufferData const&) const noexcept;
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
                                    ReadBaseStrategy,
                                    WriteBaseStrategy) noexcept;

std::unique_ptr<Port> createSerialPort(std::string dev, ReadBaseStrategy,
                                       WriteBaseStrategy) noexcept;

} // namespace strategy

#endif
// strategy/include/dev_factory.h end

#ifndef _MACRO_strategy_LIB_H_
#define _MACRO_strategy_LIB_H_

#include "common/include/lib.h"

namespace strategy {

using vup = std::vector<std::unique_ptr<strategy::Port> >;

// GEN_PROTO_BEGIN
vup StrategyPortsInitRandom(common::vu32& v);
// GEN_PROTO_END

} // namespace strategy

#endif
