#ifndef _TYPE_ERASURE_DEV_BASE_H_
#define _TYPE_ERASURE_DEV_BASE_H_

#include "types.h"
#include <memory>

namespace TypeErasureUp {

class Readable {
public:
    template<typename T>
    Readable(T x) noexcept: _self(std::make_unique<model<T> >(std::move(x))) {}
    Readable(Readable const& rhs) : _self(rhs._self->_copy()) {}
    Readable(Readable&&) noexcept = default;
    Readable& operator=(Readable const& rhs) {
        Readable tmp(rhs);
        *this = std::move(tmp);
        return *this;
    }
    Readable& operator=(Readable&&) noexcept = default;

    friend void stat(Readable const& item) noexcept { item._self->_stat(); }
    friend void write(Readable& item, BufferData const& data) noexcept {
        item._self->_write(data);
    }

    void swap(Readable& rhs) {
        using std::swap;
        swap(_self, rhs._self);
    }

private:
    struct concept_t {
        virtual ~concept_t() = default;
        virtual concept_t* _copy() const = 0;
        virtual void _stat() const noexcept = 0;
        virtual void _write(BufferData const&) noexcept = 0;
    };
    template<typename T>
    struct model final: concept_t {
        model(T x) : _data(std::move(x)) {}
        concept_t* _copy() const override { return new model(*this); }
        void _stat() const noexcept override { stat(_data); }
        void _write(BufferData const& data) noexcept override {
            write(_data, data);
        }
        T _data;
    };
    std::unique_ptr<concept_t> _self;
};

void swap(Readable& a, Readable& b);

} // namespace TypeErasureUp

#endif