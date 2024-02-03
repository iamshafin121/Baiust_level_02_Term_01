// #include <bits/stdc++.h>
// using namespace std;


// int main(){

//     int n;
//     cin >>n;
//     if(n&1){
//         cout << "NO" << endl;
//         return 0;
//     }
//     else{
//         int arr[n+2];
//         arr[0] = 0;
//         arr[n+1] = 0;
//         for(int i=1; i<=n/2; i++){
//             arr[i] = i;
//             arr[n-i+1] = (-1)*i;
//         }
//         for(int i=1; i<=n; i++){
//             cout << arr[i] << " ";
//         }
//     }


//     return 0;
// }




// #include <iostream>

// using namespace std;

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;

//         if (n % 2 == 0) {
//             cout << "YES" << endl;

//             for (int i = 1; i <= n; i++) {
//                 if (i % 2 == 1)
//                     cout << i << " ";
//                 else
//                     cout << -i << " ";
//             }
//             cout << endl;
//         } else {
//             cout << "NO" << endl;
//         }
//     }

//     return 0;
// }


#include <iostream>
using namespace std;

void Solve(){
	int n;
    cin >> n;
	if(n==3||n==5){printf("NO\n");return;}
	printf("YES\n");
	if(n%6==0){
		printf("2 -2 -1 ");
		for(int i=1;i<n/6;i++)printf("1 2 1 -1 -2 -1 ");
		printf("1 2 1\n");
	}else if(n%6==1){
		printf("-3 -3 2 ");
		for(int i=1;i<n/6;i++)printf("1 -1 -2 -1 1 2 ");
		printf("1 -1 1 -2\n");
	}else if(n%6==2){
		printf("-1 ");
		for(int i=1;i<=n/6;i++)printf("1 2 1 -1 -2 -1 ");
		printf("1\n");
	}else if(n%6==3){
		printf("-3 -3 1 2 ");
		for(int i=1;i<n/6;i++)printf("1 -1 -2 -1 1 2 ");
		printf("1 -1 -2 2 -1\n");
	}else if(n%6==4){
		printf("1 -1 ");
		for(int i=1;i<=n/6;i++)printf("1 2 1 -1 -2 -1 ");
		printf("1 2\n");
	}else{
		printf("-3 -3 1 1 -2 1 -1 ");
		for(int i=1;i<n/6;i++)printf("-2 -1 1 2 1 -1 ");
		printf("-2 2 3 -1\n");
	}
}
int main(){
	Solve();
	return 0;
}