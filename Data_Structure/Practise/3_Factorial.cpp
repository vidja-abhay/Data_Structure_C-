#include<bits/stdc++.h>
using namespace std;

int factorialRecursion(int number){
    if(number == 0 || number == 1){
        return 1;
    }

    return number * factorialRecursion(number - 1);
}

int factorialWithoutRecursion(int number){
    int ans = 1;

    for(int i=1;i<=number;i++){
        ans *= i;
    }

    return ans;
}

int main(){
    int number; cin>>number;

    int ans = factorialWithoutRecursion(number);

    cout<<ans;

    return 0;
}