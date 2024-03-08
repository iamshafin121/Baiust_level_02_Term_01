

/*
    Design a base class called Shape with a virtual function draw(). Derive classes
    Circle, Rectangle, and Triangle from Shape and override the draw() function for each
    derived class.
*/

#include <iostream>

using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing a generic shape." << endl;
    }

    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing a circle." << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() {
        cout << "Drawing a rectangle." << endl;
    }
};

class Triangle : public Shape {
public:
    void draw() {
        cout << "Drawing a triangle." << endl;
    }
};

int main() {
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;

    Shape* shape;

    shape = &circle;
    shape->draw();

    shape = &rectangle;
    shape->draw();

    shape = &triangle;
    shape->draw();

    return 0;
}
