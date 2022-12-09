#include <iostream>
#include <memory>
#include <utility>
#include <vector>

void draw(int i);
struct my_class;
void draw(my_class const&);

class drawable
{
public:
    template<typename T>
    drawable(T x) : _self(std::make_shared<model<T> >(std::move(x)))
    {
    }
    drawable(drawable const&) = default;
    drawable(drawable&&) noexcept = default;
    drawable& operator=(drawable const&) = default;
    drawable& operator=(drawable&&) noexcept = default;

    friend void draw(drawable const& item) { item._self->_draw(); }

private:
    struct concept_t {
        virtual ~concept_t() = default;
        virtual void _draw() const = 0;
    };
    template<typename T>
    struct model final: concept_t {
        model(T x) : _data(std::move(x)) {}
        void _draw() const override { draw(_data); }
        T _data;
    };
    std::shared_ptr<concept_t const> _self;
};

void draw(int i) { std::cout << "draw int " << i << std::endl; }

struct my_class {
};

void draw(my_class const&) { std::cout << "my_class" << std::endl; }

using drawables = std::vector<drawable>;

void draw(drawables const& doc)
{
    for (auto const& it : doc) {
        draw(it);
    }
}

int main()
{
    drawables doc;
    doc.push_back(35);
    doc.push_back(325);
    doc.push_back(doc);
    doc.push_back(my_class());
    draw(doc);
    return 0;
}
