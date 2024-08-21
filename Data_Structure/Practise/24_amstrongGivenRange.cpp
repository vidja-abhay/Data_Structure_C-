#include<bits/stdc++.h>
using namespace std;

int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num /= 10;
    }
    return count;
}

bool isArmstrong(int num) {
    int numDigits = countDigits(num);
    int sum = 0;
    int temp = num;
    
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, numDigits);
        temp /= 10;
    }
    
    return sum == num;
}

vector<int> amstrongGivenRange(int start, int end){
    vector<int> amstrongNumber;
    
    for(int i=start; i<=end; i++){
        if(isArmstrong(i)){
            amstrongNumber.push_back(i);
        }
    }
    
    return amstrongNumber;
}

void print(vector<int> vec){
    for(auto items : vec){
        cout<<items<<" ";
    }
}

int main(){
    int start,end;
    cin>>start;
    cin>>end;
    
    vector<int> amstrongNumber = amstrongGivenRange(start,end);
    
    print(amstrongNumber);
    return 0;
}