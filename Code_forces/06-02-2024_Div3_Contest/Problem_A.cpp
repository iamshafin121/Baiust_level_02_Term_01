#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n, B = 0, W = 0;
        cin >> n;
        string arr;
        cin >> arr;
        for(int i=0; i<n; i++){
            if(arr[i]=='B'){
                B++;
                B+=W;
                W = 0;
            }
            if(arr[i]=='W' && B>0) W++;
        }
        cout << B << endl;

    }
    

    return 0;
}