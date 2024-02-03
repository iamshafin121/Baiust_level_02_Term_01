#include <bits/stdc++.h>
using namespace std;

int main(){
    int first = 0, second = 1, n, temp;
    cout << "Enter the length of the fibonacci series : " ;
    cin >> n;
    if(n>0){
        for(int i=0; i<n; i++){
            cout << first << " ";
            temp = first + second;
            first = second;
            second = temp;
        }
        cout << endl;
    }
    else {
        cout << "Invalid length." << endl;
    }
    
    return 0;
}