#include <bits/stdc++.h>
using namespace std;

class Student{
    private :
        int a, b;
        int a1, b1;
    public :
        Student(){}
        Student (int x, int y) : a(x), b(y){}
        void set_data(int x, int y){
            a = x;
            b = y;
        }
        void input(){
            cin >> a;
            cin >> b;
        }
        void display(){
            cout << a << " " << b  << endl;
        }
};


int main(){


    // Student obj;
    // obj.set_data(10,20);
    // obj.display();

    // Student obj[4]; // Stack //

    // obj[0].set_data(0+10, 0+20); // 10 20
    // obj[1].set_data(1+10, 1+20); // 11 21
    // obj[2].set_data(2+10, 2+20); // 12 22
    // obj[3].set_data(3+10, 3+20); // 13 23

    // for(int i=0; i<4; i++){
    //     obj[i].set_data(i+10, i+20);
    // }

    // for(int i=0; i<4; i++){
    //     obj[i].display();
    // }

    // Student *ptr = new Student;

    // (*ptr).set_data(10,20);
    // ptr->set_data(10,20);
    // ptr[0].set_data(10,20);


    // Student obj;
    // int n;
    // cin >> n;
    // Student *p = new Student[n]; // dinamic memory allocation


    // for(int i=0; i<n; i++){
    //     // (*(p+i)).set_data(i+10, i+20);
    //     // (p+i)->set_data(i+10,i+20);
    //     // int a, b;
    //     // cin >> a >> b;
    //     // p[i].set_data(a,b);
    //     (*(p+i)).input();
    // }
    // for(int i=0; i<n; i++){
    //     p[i].display();
    // }




    
    





    // int a = 10;
    // int *p = &a;

    // cout << a << endl; // 10
    // cout << &a << endl; // a- address
    // cout << p << endl; // a - address
    // cout << *p << endl; // a = 10
    // cout << &p << endl; // p - address

    // int *p = new int(20);
    // // *p = 10;
    // cout << *p << endl; // 10
    // cout << &p << endl; // p - address
    // cout << p << endl; // 10 - address

    // int *p = new int[5];
    // p[0] = 10;
    // p[1] = 20;
    // p[2] = 30;
    // p[3] = 40;
    // p[4] = 50;

    // _10_ _20_ _30_ _40_ _50_

    // cout << *(p+1) << endl; //20
    // cout << p[3] << endl; // 40
    // cout << *p << endl; // 10


    // int n;
    // cin >> n;
    // int *p = new int[n];
    // for(int i=0 ; i<n; i++){
    //     cin >> *(p+i);
    // }
    // cout << endl;

    // for(int i=0 ; i<n; i++){
    //     cout << *(p+i) << " ";
    // }





    return 0;
}