#include <bits/stdc++.h>
using namespace std;


int main(){

    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        int a[n], b[m], a1[k+1] = {0}, b1[k+1] = {0};
        int A=0, B=0, c = k/2;
        for(int i=0; i<n; i++){
            cin >> a[i];
            if(a[i] <= k){
                a1[a[i]]++;
            }
        }
        for(int i=0; i<m; i++){
            cin >> b[i];
            if(b[i] <= k){
                b1[b[i]]++;
            }
        }
        for(int i=1; i<=k; i++){
            if(a1[i]>0 && b1[i]==0) A++;
            else if(a1[i]==0 && b1[i]>0) B++;
        }
        for(int i=1; i<=k; i++){
            if(a1[i]>0 && b1[i]>0){
                if(A<c) A++;
                else B++;
            }
        }
        
        if(A>=c && B>=c) cout << "YES" << endl;
        else cout << "NO" << endl;


    }

    return 0;
}