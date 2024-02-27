#include <bits/stdc++.h>
using namespace std;


int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool triangle = false;
        char arr[n][n];
        for(int i=0; i<n; i++){
            int one = 0;
            for(int j=0; j<n; j++){
                cin >> arr[i][j];
                if(arr[i][j]=='1') one++;
            }
            if(one==1) triangle = true;
        }
        if(triangle) cout << "TRIANGLE" << endl;
        else cout << "SQUARE" << endl;
    }

    return 0;
}