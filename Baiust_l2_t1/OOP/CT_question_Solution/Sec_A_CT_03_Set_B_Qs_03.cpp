


/*

    Create a class called Rectangle to represent rectangles. The class should have private
    attributes for length and width. Implement a constructor to initialize the attributes, a
    method to calculate the area, and a destructor to display a message when an object is
    destroyed.

*/

#include <bits/stdc++.h>

using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double initialLength, double initialWidth) : length(initialLength), width(initialWidth) {
        cout << "Rectangle object created with length: " << length << " and width: " << width << endl;
    }

    double calculateArea(){
        return length * width;
    }

    ~Rectangle() {
        cout << "Rectangle object destroyed. Goodbye!" << endl;
    }
};

int main() {
    Rectangle myRectangle(5.0, 3.0);
    cout << "Area of the rectangle: " << myRectangle.calculateArea() << endl;

    return 0;
}
