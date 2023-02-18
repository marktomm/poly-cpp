#include <iostream>
#include <memory>
#include <vector>

class Drawable {
public:
    template<typename T>
    Drawable(T x) : _self(std::make_shared<model<T> >(std::move(x))) {}
    Drawable(Drawable const&) = default;
    Drawable(Drawable&&) noexcept = default;
    Drawable& operator=(Drawable const&) = default;
    Drawable& operator=(Drawable&&) noexcept = default;

    friend void draw(const Drawable& drawable) { drawable._self->_draw(); }

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

    std::shared_ptr<concept_t const> _self;
};

class Circle {
public:
    explicit Circle(double radius) : _radius{radius} {}
    Circle(Circle const& rhs) : _radius{rhs._radius} {
        std::cout << "circle copy ctor\n";
    }
    Circle(Circle&&) noexcept = default;
    double radius() const { return _radius; }
    void set_radius(double value) { _radius = value; }

private:
    double _radius;
};

class Square {
public:
    explicit Square(double side) : _side{side} {}
    Square(Square const& rhs) : _side{rhs._side} {
        std::cout << "square copy ctor\n";
    }
    Square(Square&&) noexcept = default;
    double side() const { return _side; }
    void set_side(double value) { _side = value; }

private:
    double _side;
};

void draw(Circle const& circle) {
    std::cout << "Draw a circle with radius of " << circle.radius()
              << " units\n";
}
void draw(Square const& square) {
    std::cout << "Draw a square with side of " << square.side() << " units\n";
}
void draw(std::vector<Drawable> const& drawables) {
    for (auto const& drawable : drawables)
        draw(drawable);
}

int main() {
    auto drawables = std::vector<Drawable>{};
    drawables.reserve(10);
    drawables.emplace_back(Square{1});
    drawables.emplace_back(Circle{1});
    drawables.emplace_back(drawables.back());
    for (auto const& drawable : drawables) {
        draw(drawable);
    }
    return 0;
}