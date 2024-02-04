#include <bits/stdc++.h>
using namespace std;

class A{
    private:
        int a;
    public:
        A(){
            cout << "constructor" << endl;
        }
        A* getptr(){
            // cout << "This : " << this << endl;
            return this;
        } 
        A& getref(){
            // cout << "This : " << this << endl;
            return *this;
        }
        A getcpy(){
            return *this;
        } 
        void setdata(int a){
            // (*this).a = a;
            this->a = a;
        }
        void getdata(){
            cout << "a : " << a << endl; 
        }
};

int main(){

    // A a;
    // a.setdata(50);
    // a.getdata();
    // cout << &a << endl;
    // cout << a.getptr() << endl;// [a.getptr = &a] it will give object's address 

    // a.getptr()->setdata(40);
    // (*a.getptr()).getdata();// [(*a.getptr()) = a] it will give current object by pointer.
    // a.getptr()->getdata(); // [a.getptr = &a] it will give object's address and will display the data by getdata() method.

    // a.getref().setdata(30);
    // a.getref().getdata(); // [a.getref() = a] it will give object reference and will display the data by getdata() method. 


    // // copy
    // a.getcpy().setdata(60); // This will not change data.
    // a.getcpy().getdata(); // It will show the previous data.



    return 0;
}