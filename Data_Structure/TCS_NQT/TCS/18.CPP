// WRITE A PROGRAM THAT ACCEPTS TWO INTEGERS, M AND N, AND PRINTS ALL PRIME NUMBERS BETWEEN M AND N (INCLUSIVE) SUCH THAT THE SUM OF THEIR DIGIT IS ALSO A PRIME NUMBER.

#include<bits/stdc++.h>
using namespace std;

int sumOfDigit(int num){
    int sum = 0;

    while(num > 0){
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

vector<int> primeInRange(int start, int end){
    vector<bool> isPrime (end + 1, true);
    vector<int> ans;

    isPrime[0] = isPrime[1] = false;

    for(int i=2; i*i <= end ; i++){
        if(isPrime[i]){
            for(int j = i*i; j <= end; j+=i){
                isPrime[j] = false;
            }
        }
    }

    for(int i=start; i<=end; i++){
        if(isPrime[i] && isPrime[sumOfDigit(i)]) ans.push_back(i);
    }

    return ans;
}

int main(){
    int startRange, endRange;
    cout<<"Enter starting number of Range & ening number of range : ";
    cin>>startRange>>endRange;

    vector<int> ans = primeInRange(startRange, endRange);

    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;
}