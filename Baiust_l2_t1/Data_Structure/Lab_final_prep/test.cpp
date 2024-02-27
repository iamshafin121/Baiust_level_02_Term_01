// Vowel count 
// #include <iostream>
// using namespace std;
// int main() {
//     string s;
//     cout << "Enter The String: ";
//     getline(cin, s); // shafin'\0'
//     int count = 0;

//     for (int i = 0; s[i] != '\0'; i++) {
//         if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
//             count = count + 1;
//         }
//     }
//     cout << "Vowel Count: " << count << endl;
//     return 0;
// }



// Code_Fibonacci_(without_recursion):
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int first = 0; 
//     int  second = 1; 
//     int n, temp;
//     cout << "Enter the length of the Fibonacci series: "; 
//     cin >> n;
//     if(n > 0){
//         for(int i = 1; i <= n; i++){ 
//             cout << first << " "; 
//             temp = first + second;
//             first = second;
//             second = temp;
//         }
//         cout << endl;
//     } 
//     else {
//     cout << "Invalid length." << endl;
//     }
//     return 0;
// }



// // Code_Fibonacci_(with_recursion):
// #include <bits/stdc++.h>
// using namespace std;
// int fibonacci(int n){
//     if(n <= 1) return n; 
//     else return fibonacci(n - 1) + fibonacci(n - 2); 
// }
// int main(){

//     int n;
//     cout << "Enter the length of the Fibonacci series: ";
//     cin >> n;
//     for(int i = 0; i < n; i++){
//         cout << fibonacci(i) << " ";
//     }

//     return 0;
// }



// Prime number
// #include <iostream>
// using namespace std;
// int Check_prime(int num) { // 50
//     if (num <= 1) {
//         return 0;
//     }
//     for (int i = 2; i * i <= num; i++) {
//         if (num % i == 0) {
//             return 0;
//         }
//     }
//     return 1;
// }
// int main() {
//     int start, end;
//     cout << "Enter the for prime number : ";
//     cin >> start >> end;
//     if (start > end || start < 0) {
//         cout << "Invalid range. Please enter a valid range." << endl;
//         return 0;
//     }
//     cout << "Prime numbers between " << start << " and " << end << ": ";
//     for (int i = start; i <= end; i++) {
//         if (Check_prime(i)) {
//             cout << i << " ";
//         }
//     }
//     cout << endl;
//     return 0;
// }




// // Bubble Sort
// #include <iostream>
// using namespace std;
// int main() {
//     int arr[] = {64, 34, 25, 12, 22, 11, 90};  // 6
//     int n = sizeof(arr) / sizeof(arr[0]);
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - i - 1; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 swap(arr[j], arr[j + 1]);
//             }
//         }
//     }
//     cout << "Sorted array: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }



// // Frequency of any character:
// #include <iostream>
// using namespace std;
// int main(){
//     string s; // Shafin ahamed hredoy
//     cout << "Enter a String : " ;
//     // cin >> s;
//     getline(cin, s);
//     int freq[26] = {0}; // "aabc"
//     for(int i=0; i<s.size(); i++){
//         if(s[i]>='a' && s[i]<='z') freq[s[i]-'a']++;
//         else if(s[i]>='A' && s[i]<='Z') freq[s[i]-'A']++;
//     }
//     for(int i=0; i<26; i++){
//         if(freq[i]) 
//             cout << (char)(i+65) << '/' << (char)(i+97) << " = " << freq[i] << endl;
//     }
//     return 0;
// }



// // Linear search :
#include <iostream>
// using namespace std;
// int main(){
//     int arr[] = {2,3,5,7,11,13,17,19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
//     int target, index = 0;
//     bool found = false;
//     cout << "Enter Target number : " ;
//     cin >> target;
//     for(int i=0; arr[i] != '\0'; i++){
//         if(arr[i] == target){
//             found = true;
//             break;
//         }
//         index++;
//     }
//     if(found) cout << "Found in the index number : " << index << endl;
//     else cout << "Not Found!!" << endl;
//     return 0;
// }



// // Binary search :
#include <iostream>
using namespace std;
int main(){
    int arr[] = {2,3,5,7,11,13,17,19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int target;
    cout << "Enter the target number : ";
    cin >> target;
    int beg = 0, end = (sizeof(arr)/sizeof(arr[0]))-1;
    while(beg<=end){
        int mid = (beg+end)/2;
        if(arr[mid] == target){
            cout << "Found in the index number : " << mid << endl;
            return 0;
        }
        else if(target < arr[mid]) end = mid-1;
        else beg = mid + 1;
    }
    cout << "Not Found!!" << endl;
    return 0;
}



// // Palindrome Number
// #include <iostream>
// using namespace std;
// int main(){
//     int num1;
//     cin >> num1;
//     int num2 = num1;
//     int rev_num = 0;
//     while(num2){
//         rev_num = (rev_num * 10) + (num2%10);
//         num2 /= 10;
//     }
//     if(num1 == rev_num) cout << "Palindrome!" << endl;
//     else cout << "Not Palindrome!" << endl;
//     return 0;
// }



// // Palindrome String
// #include <iostream>
// using namespace std;
// int main(){
//     string s;
//     cin >> s;
//     for(int i=0, j=s.length()-1; i<j; i++,j--){
//         if(s[i] != s[j]){
//         cout << "Not Palindrome!" << endl;
//         return 0;
//         }
//     }
//     cout << "Palindrome!" << endl;
//     return 0;
// }