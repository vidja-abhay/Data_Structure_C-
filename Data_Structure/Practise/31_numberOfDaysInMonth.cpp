//Write a program to count the number of days in a given month of a year in C++
#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int month = 12, year=2012;
    
    //For checking leap year
    if(month==2 && ((year%400==0) || ((year%100!=0)&&(year%4==0))))
        cout<<"Number of days is "<< arr[month-1]+1;
    
    else cout<<"Number of days is"<<arr[month-1];
   
    
    return 0;
}