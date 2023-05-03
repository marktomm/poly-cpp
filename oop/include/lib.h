// ./common/types.h
#ifndef _COMMON_TYPES_H_
#define _COMMON_TYPES_H_

#include <cstdint>

using MutableBuffer = uint32_t;
using BufferData = uint32_t;

#endif
// ./common/types.h end
// oop/include/dev_base.h
#ifndef _OOP_DEV_BASE_H_
#define _OOP_DEV_BASE_H_

#include <string>

namespace oop {

class Port {
public:
    Port() = default;
    virtual ~Port() = default;

    virtual void Read(BufferData&) const noexcept = 0;
    virtual void Write(BufferData const&) noexcept = 0;
};

} // namespace oop

#endif
// oop/include/dev_base.h end
// oop/include/dev_impl.h
#ifndef _OOP_DEV_IMPL_H_
#define _OOP_DEV_IMPL_H_

#include <cstdint>

namespace oop {

class TcpPort final: public Port {
public:
    explicit TcpPort(std::string ip, uint16_t pn) noexcept: ip_{ip},
                                                            port_{pn},
                                                            buf_{} {}
    ~TcpPort() = default;

    void Read(BufferData&) const noexcept override;
    void Write(BufferData const&) noexcept override;

    std::string GetIp() const noexcept;
    uint16_t GetPort() const noexcept;

private:
    std::string ip_;
    uint16_t port_;
    MutableBuffer buf_;
};

class SerialPort final: public Port {
public:
    explicit SerialPort(std::string dev) noexcept: dev_{dev}, buf_{} {}
    ~SerialPort() = default;

    void Read(BufferData&) const noexcept override;
    void Write(BufferData const&) noexcept override;

    std::string GetDev() const noexcept;

private:
    std::string dev_;
    MutableBuffer buf_;
};

} // namespace oop

#endif
// oop/include/dev_impl.h end
// oop/include/dev_ctx.h
#ifndef _OOP_DEV_EXT_H_
#define _OOP_DEV_EXT_H_

#include <memory>
#include <vector>

namespace oop {

void readPorts(std::vector<std::unique_ptr<Port> > const&,
               BufferData&) noexcept;

void writePorts(std::vector<std::unique_ptr<Port> >&,
                BufferData const&) noexcept;

} // namespace oop

#endif
// oop/include/dev_ctx.h end
// oop/include/dev_factory.h
#ifndef _OOP_DEV_FACTORY_H_
#define _OOP_DEV_FACTORY_H_

#include <memory>
#include <string>

#include <cstdint>

namespace oop {

std::unique_ptr<Port> createTcpPort(std::string ip, uint16_t port) noexcept;

std::unique_ptr<Port> createSerialPort(std::string dev) noexcept;

} // namespace oop

#endif
// oop/include/dev_factory.h end

#ifndef _MACRO_oop_LIB_H_
#define _MACRO_oop_LIB_H_
namespace oop {

using vb = std::vector<bool>;
using vu32 = std::vector<uint32_t>;
using vup = std::vector<std::unique_ptr<oop::Port> >;

// GEN_PROTO_BEGIN
int getRandom12();
int getRandom13();
std::size_t GetNextGlobalIndex();
vb GetGlobalRandBoolVec();
void emptyFn();
void emptyFnInt();
vu32 GetGlobalRandIntVec();
vup OopPortsInitRandom(vu32& v);
// GEN_PROTO_END

} // namespace oop

#endif
