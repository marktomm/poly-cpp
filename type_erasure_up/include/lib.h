// ./common/include/lib.h
#ifndef _COMMON_TYPES_H_
#define _COMMON_TYPES_H_

#include <cstdint>

using MutableBuffer = uint32_t;
using BufferData = uint32_t;

#endif
// ./common/include/lib.h end
// type_erasure_up/include/dev_base.h
#ifndef _TYPE_ERASURE_DEV_BASE_H_
#define _TYPE_ERASURE_DEV_BASE_H_

#include <memory>

namespace type_erasure_up {

// templated ctor
// non-virtual iface
// External Polymorphism + Bridge + Prototype

class Readable {
public:
    template<typename T>
    Readable(T x) noexcept: _self(std::make_unique<model<T> >(std::move(x))) {}
    // GOF: Prototype
    Readable(Readable const& rhs) : _self(rhs._self->_copy()) {}
    Readable(Readable&&) noexcept = default;
    // GOF: Prototype
    Readable& operator=(Readable const& rhs) {
        Readable tmp(rhs);
        *this = std::move(tmp);
        return *this;
    }
    Readable& operator=(Readable&&) noexcept = default;

    friend void read(Readable const& item, BufferData& output) noexcept {
        item._self->_read(output);
    }
    friend void write(Readable& item, BufferData const& data) noexcept {
        item._self->_write(data);
    }

    void swap(Readable& rhs) {
        using std::swap;
        swap(_self, rhs._self);
    }

private:
    // GOF: Bridge. Implementation interface
    // External Polymorphism
    struct concept_t {
        virtual ~concept_t() = default;
        // GOF: Prototype
        virtual concept_t* _copy() const = 0;
        virtual void _read(BufferData&) const noexcept = 0;
        virtual void _write(BufferData const&) noexcept = 0;
    };

    // GOF: Bridge. Concrete implementation
    // External Polymorphism
    template<typename T>
    struct model final: concept_t {
        model(T x) : _data(std::move(x)) {}
        // GOF: Prototype
        concept_t* _copy() const override { return new model(*this); }
        void _read(BufferData& output) const noexcept override {
            read(_data, output);
        }
        void _write(BufferData const& data) noexcept override {
            write(_data, data);
        }
        T _data;
    };

    // K. Iglberger: this is a bridge between our abstractions and the real
    // representation that is represented by the Readable
    // GOF: Bridge. Implementation composite
    std::unique_ptr<concept_t> _self;
};

void swap(Readable& a, Readable& b);

} // namespace type_erasure_up

#endif
// type_erasure_up/include/dev_base.h end
// type_erasure_up/include/dev_impl.h
#ifndef _TYPE_ERASURE_DEV_IMPL_H_
#define _TYPE_ERASURE_DEV_IMPL_H_

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
// type_erasure_up/include/dev_impl.h end
// type_erasure_up/include/dev_algo.h
#ifndef _TYPE_ERASURE_DEV_ALGO_H_
#define _TYPE_ERASURE_DEV_ALGO_H_

namespace type_erasure_up {

void read(TcpPort const&, BufferData&) noexcept;
void write(TcpPort&, BufferData const&) noexcept;

void read(SerialPort const&, BufferData&) noexcept;
void write(SerialPort&, BufferData const&) noexcept;

} // namespace type_erasure_up

#endif
// type_erasure_up/include/dev_algo.h end
// type_erasure_up/include/dev_ctx.h
#ifndef _TYPE_ERASURE_DEV_EXT_H_
#define _TYPE_ERASURE_DEV_EXT_H_

#include <memory>
#include <vector>

namespace type_erasure_up {

void readPorts(std::vector<Readable> const&, BufferData&) noexcept;

void writePorts(std::vector<Readable>&, BufferData const&) noexcept;

} // namespace type_erasure_up

#endif
// type_erasure_up/include/dev_ctx.h end
// type_erasure_up/include/dev_factory.h
#ifndef _TYPE_ERASURE_UP_DEV_FACTORY_H_
#define _TYPE_ERASURE_UP_DEV_FACTORY_H_

#include <memory>
#include <string>

#include <cstdint>

namespace type_erasure_up {

Readable createTcpPort(std::string ip, uint16_t port) noexcept;

Readable createSerialPort(std::string dev) noexcept;

} // namespace type_erasure_up

#endif
// type_erasure_up/include/dev_factory.h end
