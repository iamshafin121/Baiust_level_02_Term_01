


/*
    Create a class named Circle, implement a parameterized constructor that allows users
    to initialize the object&#39;s properties during instantiation.
*/

#include <bits/stdc++.h>

using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(double initialRadius) : radius(initialRadius) {
        cout << "Circle object created with radius: " << radius << endl;
    }

    double getRadius(){
        return radius;
    }

    ~Circle() {
        cout << "Circle object destroyed. Goodbye!" << endl;
    }
};

int main() {
    Circle myCircle(4.5);
    cout << "Radius of the circle: " << myCircle.getRadius() << endl;

    return 0;
}
