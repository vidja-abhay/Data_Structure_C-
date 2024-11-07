#include<bits/stdc++.h>
using namespace std;

bool isAutomorphic(int n){
    int square = n * n;
    string nStr = to_string(n);
    string squareStr = to_string(square);
    
    return squareStr.substr(squareStr.length() - nStr.length()) == nStr;
}

int main(){
    int n;
    cout << "Enter a number to check if it is automorphic or not: ";
    cin >> n;
    if(isAutomorphic(n)) 
        cout << "Given number is automorphic" << endl;
    else 
        cout << "Given number is not automorphic" << endl;
    return 0;
}