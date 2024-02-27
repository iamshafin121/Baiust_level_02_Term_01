#include <bits/stdc++.h>
using namespace std;


int main(){

    long long t;
    cin >> t;
    while(t--){
        long long n , k;
        cin >> n >> k;
        // long long arr1[(n/2)+1];
        // long long arr2[(n/4)+1];
        // long long arr3[(n/6)+1];
        set<long long> arr;
        set<long long>::iterator it;

        
        for(long long i=1; i<=n; ){
            arr.insert(i);
            i += 2;
        }

        for(long long i=1; i<=n; ){
            long long k = i*2;
            if(k<=n){
                arr.insert(k);
            }
            else if(k>=n) break;
            i += 2;
        }

        for(long long i=1; i<=n; ){
            long long k = i*3;
            if(k<=n){
                arr.insert(k);
            }
            else if(k>=n) break;
            i += 2;
        }

        for(long long i=1; i<=n; ){
            long long k = i*4;
            if(k<=n){
                arr.insert(k);
            }
            else if(k>=n) break;
            i += 2;
        }
        long long v = 1;
        for (it = arr.begin(); it != arr.end(); ++it) {
            if(v==k){
                cout << *it << endl;
            }
            v++;
        }
            

    }

    return 0;
}