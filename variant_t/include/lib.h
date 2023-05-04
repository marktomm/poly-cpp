// ./common/include/lib.h
#ifndef _COMMON_TYPES_H_
#define _COMMON_TYPES_H_

#include <cstdint>

using MutableBuffer = uint32_t;
using BufferData = uint32_t;

#endif
// ./common/include/lib.h end
// variant_t/include/dev_impl.h
#ifndef _VARIANT_DEV_IMPL_H_
#define _VARIANT_DEV_IMPL_H_

#include <string>

#include <cstdint>

namespace variant_t {

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

} // namespace variant_t

#endif
// variant_t/include/dev_impl.h end
// variant_t/include/dev_algo.h
#ifndef _VARIANT_DEV_ALGO_H_
#define _VARIANT_DEV_ALGO_H_

namespace variant_t {

class Read {
public:
    void operator()(TcpPort const&, BufferData& output) const noexcept;
    void operator()(SerialPort const&, BufferData& output) const noexcept;
};

class Write {
public:
    void operator()(TcpPort&, BufferData const&) const noexcept;
    void operator()(SerialPort&, BufferData const&) const noexcept;
};

} // namespace variant_t

#endif
// variant_t/include/dev_algo.h end
// variant_t/include/dev_ctx.h
#ifndef _VARIANT_DEV_EXT_H_
#define _VARIANT_DEV_EXT_H_

#include <variant>

#include <memory>
#include <vector>

namespace variant_t {

using Port = std::variant<TcpPort, SerialPort>;
using WriteData = std::variant<BufferData>;
using ReadData = std::variant<BufferData>;

void readPorts(std::vector<Port> const&, ReadData&) noexcept;

void writePorts(std::vector<Port>&, WriteData const&) noexcept;

} // namespace variant_t

#endif
// variant_t/include/dev_ctx.h end
// variant_t/include/dev_factory.h
#ifndef _VARIANT_T_DEV_FACTORY_H_
#define _VARIANT_T_DEV_FACTORY_H_

#include <memory>
#include <string>

#include <cstdint>

namespace variant_t {

Port createTcpPort(std::string ip, uint16_t port) noexcept;

Port createSerialPort(std::string dev) noexcept;

} // namespace variant_t

#endif
// variant_t/include/dev_factory.h end

#ifndef _MACRO_variant_t_LIB_H_
#define _MACRO_variant_t_LIB_H_

#include "common/include/lib.h"

namespace variant_t {

using vup = std::vector<variant_t::Port>;

// GEN_PROTO_BEGIN
vup VarianttPortsInitRandom(common::vu32& v);
// GEN_PROTO_END

class Firewall {
public:
    explicit Firewall(std::string ip) noexcept: ip_{ip} {}
    ~Firewall() = default;

private:
    std::string ip_;
};

using Network = std::variant<TcpPort, Firewall>;

class GetStatus {
public:
    std::string operator()(TcpPort const& tcpPort) const noexcept;
    std::string operator()(Firewall const& firewall) const noexcept;
};

} // namespace variant_t

#endif
