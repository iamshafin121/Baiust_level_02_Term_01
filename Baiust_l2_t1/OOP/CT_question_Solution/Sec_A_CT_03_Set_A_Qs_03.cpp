


/*
    Create a simple class called Student with the following attributes: name (a string) and
    id (an integer). Implement the class with a constructor to initialize the attributes and a
    destructor to display a farewell message when an object of the class is destroyed.
*/


#include <bits/stdc++.h>
using namespace std;
class Student {
private:
    string name;
    int id;

public:
    Student(string studentName, int studentId) : name(studentName), id(studentId) {
        cout << "Student " << name << " with ID " << id << " is created." << endl;
    }

    ~Student() {
        cout << "Farewell! Student " << name << " with ID " << id << " is destroyed." << endl;
    }
};

int main() {

    Student student1("JON", 123);

    return 0;
}
