


// Provide an example demonstrating the implementation of encapsulation in a C++ class.

#include <bits/stdc++.h>

using namespace std;

class Student {
private:
    string name;
    int age;

public:
    void setName(string studentName) {
        name = studentName;
    }

    string getName(){
        return name;
    }

    void setAge(int studentAge) {
        age = studentAge;
    }

    int getAge() {
        return age;
    }

    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student student1;

    student1.setName("JON");
    student1.setAge(20);

    cout << "Student Information:" << endl;
    cout << "Name: " << student1.getName() << ", Age: " << student1.getAge() << endl;

    student1.displayInfo();

    return 0;
}
