#include <iostream>
#include <memory>
#include <vector>

void draw(int i);

class drawable {
public:
    template<typename T>
    drawable(T x) : _self(std::make_unique<model<T> >(std::move(x))) {}
    drawable(drawable const& rhs) : _self(rhs._self->_copy()) {}
    drawable(drawable&&) noexcept = default;
    drawable& operator=(drawable const& rhs) {
        drawable tmp(rhs);
        *this = std::move(tmp);
        return *this;
    }
    drawable& operator=(drawable&&) noexcept = default;

    friend void draw(drawable const& item) { item._self->_draw(); }

private:
    struct concept_t {
        virtual ~concept_t() = default;
        virtual concept_t* _copy() const = 0;
        virtual void _draw() const = 0;
    };
    template<typename T>
    struct model final: concept_t {
        model(T x) : _data(std::move(x)) {}
        concept_t* _copy() const override { return new model(*this); }
        void _draw() const override { draw(_data); }
        T _data;
    };
    std::unique_ptr<concept_t> _self;
};

void draw(int i) { std::cout << "draw int " << i << std::endl; }

struct my_class {};

void draw(my_class const&) { std::cout << "my_class" << std::endl; }

using drawables = std::vector<drawable>;

void draw(drawables const& doc) {
    for (auto const& it : doc) {
        draw(it);
    }
}

int main() {
    drawables doc;
    doc.push_back(35);
    doc.push_back(325);
    doc.push_back(doc);
    doc.push_back(my_class());
    draw(doc);
    return 0;
}
