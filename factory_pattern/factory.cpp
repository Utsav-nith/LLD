#include <iostream>
#include <string>

class Shape {
public:
    virtual std::string draw() = 0;
};

class Circle : public Shape {
public:
    std::string draw() override {
        return "Draw Circle";
    }
};

class Rectangle : public Shape {
public:
    std::string draw() override {
        return "Draw Rectangle";
    }
};

class Square : public Shape {
public:
    std::string draw() override {
        return "Draw Square";
    }
};

class ShapeFactory {
public:
    static Shape* getShape(const std::string& shape) {
        if (shape == "circle") {
            return new Circle();
        } else if (shape == "rectangle") {
            return new Rectangle();
        } else if (shape == "square") {
            return new Square();
        } else {
            return new Circle(); // Default to Circle
        }
    }
};

int main() {
    Shape* s = ShapeFactory::getShape("circle");
    std::cout << s->draw() << std::endl;
    
    delete s; // Don't forget to delete dynamically allocated objects

    return 0;
}