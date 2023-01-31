#ifndef _TYPE_ERASURE_DEV_BASE_H_
#define _TYPE_ERASURE_DEV_BASE_H_

#include <memory>

class statable
{
public:
    template<typename T>
    statable(T x) : _self(std::make_unique<model<T> >(std::move(x)))
    {
    }
    statable(statable const& rhs) : _self(rhs._self->_copy()) {}
    statable(statable&&) noexcept = default;
    statable& operator=(statable const& rhs)
    {
        statable tmp(rhs);
        *this = std::move(tmp);
        return *this;
    }
    statable& operator=(statable&&) noexcept = default;

    friend void stat(statable const& item) { item._self->_stat(); }

private:
    struct concept_t {
        virtual ~concept_t() = default;
        virtual concept_t* _copy() const = 0;
        virtual void _stat() const = 0;
    };
    template<typename T>
    struct model final: concept_t {
        model(T x) : _data(std::move(x)) {}
        concept_t* _copy() const override { return new model(*this); }
        void _stat() const override { stat(_data); }
        T _data;
    };
    std::unique_ptr<concept_t> _self;
};

#endif