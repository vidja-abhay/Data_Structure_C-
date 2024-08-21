#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num1 = 12, num2 = 14, num3 = 15, lcm;
    int maximum = max(num1, max(num2, num3));
    
    for(int i = maximum ; i <= num1*num2*num3 ; i++)
    {
        if(i % num1 == 0 && i % num2 == 0 && i%num3==0){
            lcm = i;
            break;
        }
    }
    
    cout<<"LCM of "<<num1<<" and "<<num2<<" is "<<lcm;
    return 0;
}