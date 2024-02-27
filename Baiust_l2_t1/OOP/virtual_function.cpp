#include <bits/stdc++.h>
using namespace std;

class A{
    public:
        void get_data(){
            cout << "value from (class A) : "<< endl;
        }
        void display(){
            cout << "Value from (class A) : "<< endl;
        }
};

class B : public A{
    public:
        void get_data(){
            cout << " value from (class B) : "<< endl;
        }
        void display(){
            cout << "Value from (class B) : "<< endl;
        }
};


int main(){

  
    B obj;
    obj.get_data();





    return 0;
}