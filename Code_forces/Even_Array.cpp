#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n, even = 0, odd = 0, right = 0;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(i%2==0){
                if(arr[i]%2==0){
                    right++;
                }
                else{
                    even++;
                }
            }
            else{
                if(arr[i]%2 != 0){
                    right++;
                }
                else{
                    odd++;
                }
            }
        }
        if(n==right) cout << "0" << endl;
        else if(even==odd) cout << even << endl;
        else cout << "-1" << endl;
    }

    return 0;
}