#include <bits/stdc++.h>
using namespace std;

class Complex{
    private:
        int real, imag;
    public:
        Complex(int r=0, int i=0): real(r), imag(i){}
        const Complex operator+(Complex const &obj) const {
            Complex num;
            cout << "real : " << real << endl;
            cout << "imag : " << imag << endl;
            cout << "obj.real : " << obj.real << endl;
            cout << "obj.imag : " << obj.imag << endl;
            num.real = real + obj.real;
            num.imag = imag + obj.imag;
            return num;
        }
};

int main(){

    Complex c1(10,20), c2(20,10), c3;

    c3 = c1 + c2;



    return 0;
}