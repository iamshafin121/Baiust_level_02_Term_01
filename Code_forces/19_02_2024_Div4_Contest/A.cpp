#include <bits/stdc++.h>
using namespace std;


int main(){

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int A = 0, B = 0;
        for(int i : s){
            if(i=='A') A++;
            else B++;
        }
        if(A>B) cout << "A" << endl;
        else cout << "B" << endl;
    }


    return 0;
}