#include <bits/stdc++.h>
using namespace std;



class A{
    
    string b = "flatu";
    public:
    int a = 10;
        void set(int x){
            a = x;
        }
        A operator+(A&obj){ 
            A ob;
            ob.a = a + obj.a;

            return ob;
        }
        void display(){
            cout << a << endl;
        }

};


int main(){

    A obj1; // a = 10
    A obj2; // a = 10
    // obj2.set(20);
    obj2.a = 20;
    obj2.display(); // 10

    A obj3; // a = 10
    obj3.display(); // 10

    obj3 = obj1+obj2;

    obj3.display(); // 20


    return 0;
}