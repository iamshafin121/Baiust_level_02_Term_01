#include <iostream>

using namespace std;

int main(){

    short int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        if(b<a){
            if(b>c){
                cout << b << endl;
            }
            else if(c>a){
                cout << a << endl;
            }
            else {
                cout << c << endl;
            }
        }
        else {
            if(c<a){
                cout << a << endl;
            }
            else if (c>b){
                cout << b << endl;
            }
            else{
                cout << c << endl;
            }
        }
    }

    return 0;
}