#include <bits/stdc++.h>
using namespace std;

void operation(int &big,int &sml,int avr){
    int have = big-avr;
    int need = avr-sml;
    if(need<=have){
        big -= need;
        sml += need;
    }
    else{
        big -= have;
        sml += have;
    }
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n, sum = 0;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
            sum += arr[i];
        }
        int avr = sum/n;
        if((avr*n)!=sum){
            cout << "NO" << endl;
            goto end;
        }
        if(arr[n-1]>avr){
            cout << "NO" << endl;
            goto end;
        }
        for(int i=0; i<n-1; i++){
            if(arr[i]<avr){
                cout << "NO" << endl;
                goto end;
            }
            else if(arr[i]>avr){
                for(int j=i+1; j<n; j++){
                    if(arr[j]<avr){
                        operation(arr[i],arr[j],avr);
                    }
                }
            }
        }
        if(arr[n-1]!=avr){
            cout << "NO" << endl;
            goto end;
        }
        else{
            cout << "YES" << endl;
        }
        end:
    {}
    }
    return 0;
}