#include <iostream>
#include <memory>
#include <vector>

void draw(int i);

class Drawable {
public:
    template<typename T>
    Drawable(T x) : _self(std::make_unique<model<T> >(std::move(x))) {}

    Drawable(Drawable const& rhs) : _self(rhs._self->_copy()) {}
    Drawable(Drawable&&) noexcept = default;
    Drawable& operator=(Drawable const& rhs) {
        Drawable tmp(rhs);
        *this = std::move(tmp);
        return *this;
    }
    Drawable& operator=(Drawable&&) noexcept = default;

    friend void draw(Drawable const& drawable) { drawable._self->_draw(); }

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

void draw(int i) { std::cout << "draw int " << i << std::endl; }

int main() {
    auto drawables = std::vector<Drawable>{};
    drawables.reserve(10);
    drawables.emplace_back(1);
    drawables.emplace_back(Square{1});
    drawables.emplace_back(Circle{1});
    drawables.emplace_back(drawables.back());
    drawables.emplace_back(drawables);
    draw(drawables);
    return 0;
}