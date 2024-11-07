// GIVEN AN INTEGER, WE NEED TO FIND THE SUM OF VALUES OF THAT TABLE.
// I/P = 10, O/P : 550
// EX : I/P = 10, O/P : 10*1 + 10*2 + .... + 10*10 = 550

#include<bits/stdc++.h>
using namespace std;

int findSum(int n){
    int sum = 0;

    for(int i=1; i<=10; i++){
        sum += n*i;
    }

    return sum;
}

int sumOfTable(int n) {
    return (n * 55);
}

int sumOfTableUpToN(int n) {
    return (n * n * (n + 1)) / 2;
}

int main(){
    int num;
    cin>>num;

    int sum = findSum(num);

    cout<<sum<<endl;

    int sum2 = sumOfTable(num);

    cout<<sum2<<endl;
}