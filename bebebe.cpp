#include <cmath>
#include <vector>


class Shape {
public:
    // TODO: объявите чисто виртуальные методы area() и perimeter()
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Shape() = default;
};

// TODO: реализуйте классы и методы
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double width, double height) : width(width), height(height) {}
    double area() const override {
        return width * height;
    }
    double perimeter() const override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
private:
    double a, b, c;
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}
    double perimeter() const override {
        return a + b + c;
    }
    double area() const override {
        double s = perimeter() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};


bool operator<(const Shape& lhs, const Shape& rhs) {
    return lhs.area() < rhs.area();
}

bool operator>(const Shape& lhs, const Shape& rhs) {
    return lhs.area() > rhs.area();
}

bool operator<=(const Shape& lhs, const Shape& rhs) {
    return lhs.area() <= rhs.area();
}

bool operator>=(const Shape& lhs, const Shape& rhs) {
    return lhs.area() >= rhs.area();
}

std::vector<Shape*> sortShapes(const std::vector<Shape*>& shapes) {
    std::vector<Shape*> sortedShapes = shapes;
    for (size_t i = 0; i < sortedShapes.size() - 1; ++i) {
        for (size_t j = 0; j < sortedShapes.size() - i - 1; ++j) {
            if (*sortedShapes[j] > *sortedShapes[j + 1]) {
                std::swap(sortedShapes[j], sortedShapes[j + 1]);
            }
        }
    }
    return sortedShapes;
}
