#ifndef _TYPE_ERASURE_DEV_BASE_H_
#define _TYPE_ERASURE_DEV_BASE_H_

#include "types.h"
#include <memory>

namespace TypeErasureUp {

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

} // namespace TypeErasureUp

#endif