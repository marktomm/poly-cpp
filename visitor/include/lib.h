// ./common/types.h
#ifndef _COMMON_TYPES_H_
#define _COMMON_TYPES_H_

#include <cstdint>

using MutableBuffer = uint32_t;
using BufferData = uint32_t;

#endif
// ./common/types.h end
// visitor/include/dev_base.h
#ifndef _VISITOR_DEV_BASE_H_
#define _VISITOR_DEV_BASE_H_

#include <string>

namespace visitor {

class Port {
public:
    Port() = default;
    virtual ~Port() = default;

    class Visitor;
    virtual void accept(Visitor const&) const noexcept = 0;
    virtual void accept(Visitor const&) noexcept = 0;
};

} // namespace visitor

#endif
// visitor/include/dev_base.h end
// visitor/include/dev_impl.h
#ifndef _VISITOR_DEV_IMPL_H_
#define _VISITOR_DEV_IMPL_H_


#include <cstdint>

namespace visitor {

class TcpPort final: public Port {
public:
    explicit TcpPort(std::string ip, uint16_t pn) noexcept: ip_{ip},
                                                            port_{pn},
                                                            buf_{} {}
    ~TcpPort() = default;

    void accept(Visitor const&) const noexcept override;
    void accept(Visitor const&) noexcept override;

    void Read(BufferData&) const noexcept;
    void Write(BufferData const&) noexcept;

private:
    std::string ip_;
    uint16_t port_;
    MutableBuffer buf_;
};

class SerialPort final: public Port {
public:
    explicit SerialPort(std::string dev) noexcept: dev_{dev}, buf_{} {}
    ~SerialPort() = default;

    void accept(Visitor const&) const noexcept override;
    void accept(Visitor const&) noexcept override;

    void Read(BufferData&) const noexcept;
    void Write(BufferData const&) noexcept;

private:
    std::string dev_;
    MutableBuffer buf_;
};

class Port::Visitor {
public:
    virtual ~Visitor() = default;

    virtual void visit(TcpPort const&) const noexcept = 0;
    virtual void visit(SerialPort const&) const noexcept = 0;

    virtual void visit(TcpPort&) const noexcept = 0;
    virtual void visit(SerialPort&) const noexcept = 0;
};

} // namespace visitor

#endif
// visitor/include/dev_impl.h end
// visitor/include/dev_algo.h
#ifndef _VISITOR_DEV_ALGO_H_
#define _VISITOR_DEV_ALGO_H_


namespace visitor {

class Read final: public Port::Visitor {
public:
    Read(BufferData& output) : data_{output} {}
    void visit(TcpPort const&) const noexcept override;
    void visit(SerialPort const&) const noexcept override;
    void visit(TcpPort&) const noexcept override;
    void visit(SerialPort&) const noexcept override;

private:
    BufferData& data_;
};

class Write final: public Port::Visitor {
public:
    Write(BufferData const& data) : data_{data} {}
    void visit(TcpPort const&) const noexcept override;
    void visit(SerialPort const&) const noexcept override;
    void visit(TcpPort&) const noexcept override;
    void visit(SerialPort&) const noexcept override;

private:
    BufferData const& data_;
};

} // namespace visitor

#endif
// visitor/include/dev_algo.h end
// visitor/include/dev_ctx.h
#ifndef _VISITOR_DEV_EXT_H_
#define _VISITOR_DEV_EXT_H_


#include <memory>
#include <vector>

namespace visitor {

void readPorts(std::vector<std::unique_ptr<Port> > const&,
               BufferData&) noexcept;

void writePorts(std::vector<std::unique_ptr<Port> >&,
                BufferData const&) noexcept;

} // namespace visitor

#endif
// visitor/include/dev_ctx.h end
// visitor/include/dev_factory.h
#ifndef _VISITOR_DEV_FACTORY_H_
#define _VISITOR_DEV_FACTORY_H_


#include <memory>
#include <string>

#include <cstdint>

namespace visitor {

std::unique_ptr<Port> createTcpPort(std::string ip, uint16_t port) noexcept;

std::unique_ptr<Port> createSerialPort(std::string dev) noexcept;

} // namespace visitor

#endif
// visitor/include/dev_factory.h end
