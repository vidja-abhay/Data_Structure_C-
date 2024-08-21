#include<bits/stdc++.h>
using namespace std;

bool isHarshad(int n){
    int temp = n, sum = 0;

    while(temp > 0){
        sum += temp%10;
        temp /= 10;
    }

    return n%sum == 0;
}

int main(){
    int n;
    cout << "Enter a number to check if it is harshad or not: ";
    cin >> n;
    if(isHarshad(n)) 
        cout << "Given number is harshad" << endl;
    else 
        cout << "Given number is not harshad" << endl;
    return 0;
}