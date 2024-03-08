


/*
    Write a c++ program to store GPA of n number of students and display it using the technique of Dynamic memory allocation. And also don't forget to release the used memory after executing your program.
*/

#include <bits/stdc++.h>
using namespace std;

class Student {
private:
    double gpa;

public:
    Student() : gpa(0.0) {}

    void inputGPA() {
        cout << "Enter GPA for the student: ";
        cin >> gpa;
    }

    void displayGPA() const {
        cout << "GPA: " << gpa << endl;
    }
};

int main() {
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    Student* studentArray = new Student[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        cout << "\nDetails for student " << i + 1 << ":\n";
        studentArray[i].inputGPA();
    }

    cout << "\nStored GPAs:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << "Student " << i + 1 << " - ";
        studentArray[i].displayGPA();
    }

    delete[] studentArray;

    return 0;
}
