#include <iostream>
using namespace std;

int main(){

    int a[5];
    cin >> a[1] >> a[2] >> a[3] >> a[4];

    string s;
    cin >> s;
    int count = 0;
    for (int i=0; i<s.length(); i++){
        count += a[s[i]-'0'];
    }
    cout << count << endl;
    
    return 0;
}