#include <iostream>
using namespace std;

class Test{
    private:
        int a;
        int b;
    public:
        // Test(int x, int y) : a(x), b(y)
        // Test(int x, int y) : b(x), a(y)
        // Test(int x, int y) : a(x+y), b(y+x)
        // Test(int x, int y) : a(x+3), b(y*3)
        // Test(int x, int y) : a(x-1), b(y/2)
        // Test(int x, int y) : b(y), a(x)
        // Test(int x, int y) : a(x), b(y+a)
        // Test(int x, int y) : a(x+b), b(y) // b=0
        // Test(int i, int j) : b(j), a(i+b) // b will not be added. b=0 will be count
        Test(int i, int j) : b(j+a), a(i+b)
        {
            cout << "A = " << a << endl;
            cout << "B = " << b << endl;
        }
    
};


int main(){
    
    Test t(15,15);
    
    return 0;
}