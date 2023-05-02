// ./common/types.h
#ifndef _COMMON_TYPES_H_
#define _COMMON_TYPES_H_

#include <cstdint>

using MutableBuffer = uint32_t;
using BufferData = uint32_t;

#endif
// ./common/types.h end
// enum_type/include/dev_base.h
#ifndef _DEV_BASE_H_
#define _DEV_BASE_H_
namespace Enum {

enum PortType { tcp, serial, end_ = 0xFFFFFFFF };
class Port {
public:
    explicit Port(PortType pt) noexcept: type_{pt} {}
    virtual ~Port() = default;

    PortType GetType() const noexcept { return type_; }

private:
    PortType type_;
};

} // namespace Enum

#endif
// enum_type/include/dev_base.h end
// enum_type/include/dev_impl.h
#ifndef _DEV_IMPL_H_
#define _DEV_IMPL_H_

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
// enum_type/include/dev_impl.h end
// enum_type/include/dev_algo.h
#ifndef _ENUM_DEV_ALGO_H_
#define _ENUM_DEV_ALGO_H_

namespace Enum {

void read(TcpPort const&, BufferData&) noexcept;
void write(TcpPort&, BufferData const&) noexcept;

void read(SerialPort const&, BufferData&) noexcept;
void write(SerialPort&, BufferData const&) noexcept;

} // namespace Enum

#endif
// enum_type/include/dev_algo.h end
// enum_type/include/dev_ctx.h
#ifndef _DEV_EXT_H_
#define _DEV_EXT_H_

#include <memory>
#include <vector>

namespace Enum {

void readPorts(std::vector<std::unique_ptr<Port> > const&,
               BufferData& output) noexcept;

void readPort(std::unique_ptr<Port> const&, BufferData& output) noexcept;

void writePorts(std::vector<std::unique_ptr<Port> >&,
                BufferData const&) noexcept;

void writePort(std::unique_ptr<Port>&, BufferData const&) noexcept;
void writePort(Port*, BufferData const&) noexcept;

} // namespace Enum

#endif
// enum_type/include/dev_ctx.h end
// enum_type/include/dev_factory.h
#ifndef _ENUM_DEV_FACTORY_H_
#define _ENUM_DEV_FACTORY_H_

#include <memory>
#include <string>

#include <cstdint>

namespace Enum {

std::unique_ptr<Port> createTcpPort(std::string ip, uint16_t port) noexcept;

std::unique_ptr<Port> createSerialPort(std::string dev) noexcept;

} // namespace Enum

#endif
// enum_type/include/dev_factory.h end

#ifndef _MACRO_enum_type_LIB_H_
#define _MACRO_enum_type_LIB_H_
namespace enum_type {
std::vector<uint32_t> setup();

std::vector<std::unique_ptr<Enum::Port> >
EnumPortsInitRandom(std::vector<uint32_t>& v);

} // namespace enum_type

#endif
