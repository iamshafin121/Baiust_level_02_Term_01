#include <bits/stdc++.h>
using namespace std;

class Student{
    int a, b;
    public:
        Student(){}
        Student(int x, int y): a(x), b(y){}
        void set_data(int x, int y){
            a = x;
            b = y;
        }
        void operator ++ (){

             a = a+5;
             b = b+5;
            
        }
        Student operator+ (Student &obj){
            Student x;
            x.a = a - obj.a;
            x.b = b - obj.b;
            return x;
        }
        void display(){
            cout << "a = " << a << " b = " << b << endl;
        }
};

int main(){

    // function overloading, operator overloading --- >> complile time polymorphism
    // virtual function --- >> runtime polymorphism

    Student obj1;
    obj1.set_data(10,20);
    Student obj2;
    obj2.set_data(30,40); //40 60
    ++obj2;
    obj2.display();
    Student obj4 = obj2+obj1;
    obj4.display();
    



    return 0;
}