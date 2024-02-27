#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int first=1, second=1, third=1;
        for(int i=3; i<n; i++){
            if(third < 26) third++;
            else if(second < 26) second++;
            else first++;
        }
        cout << char (first+96) << char (second+96) << char (third+96) << endl;
    }
    return 0;
}