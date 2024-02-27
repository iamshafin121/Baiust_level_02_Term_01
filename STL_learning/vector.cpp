#include <bits/stdc++.h>
using namespace std;

template <class T>
void display_vector(vector<T> &v){
    for(auto i : v){
        cout << i << " ";
    }
}

int main(){

    vector<int> v(5,15);

    // int n;
    // cin >> n;
    // for(int i=0; i<n; i++){
    //     int m;
    //     cin >> m;
    //     v.push_back(m);
    // }

    vector<int> :: iterator i = v.begin();
    for(; i != v.end(); i++){
        cout << *i << " ";
    }
    cout << endl;
    v.pop_back();
    v.pop_back();
    v.pop_back();
    display_vector(v);
    cout << endl;

    for(int i = 0; i<5; i++){ 
        cout << v[i] << " "; // we did pop_back(); b
    }
    cout << endl;


    return 0;
}