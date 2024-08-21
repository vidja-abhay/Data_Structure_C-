//C++ Program
//Sum of digits in a number
#include<iostream>
using namespace std;

int main ()
{
    int num, sum = 0;
 
    num=1234;
    cout <<"\nThe number is: " << num; 
 
    //loop to find sum of digits
    while(num!=0){
        sum += num % 10;
        num = num / 10;
    }
 
    //output
    cout <<"\nSum of digits: " << sum;
 
    return 0;
}
// Time complexity : O(N)
// Space complexity : O(1)
// where N is number of digits in num