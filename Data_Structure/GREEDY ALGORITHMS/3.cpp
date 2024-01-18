// CHECK IF IT IS POSSIBLE TO SURVIVE ON ISLAND
// GREEK FOR GREEKS

#include<bits/stdc++.h>
using namespace std;

int minimumDays(int s,int n,int m)
{
    int sunday = s/7;
    int buyingdays = s - sunday;
    int totalFood = s*m;
    int ans = 0;

    if(totalFood % n == 0)
    {
        ans = totalFood/n;
    }
    
    else
    {
        ans = totalFood/n + 1;
    }

    if(ans <= buyingdays)
    {
        return ans;
    }

    else
    {
        return -1;
    }
}

int main()
{
    cout<<"ENTER THE SURVIVE DAYS : ";
    int s; cin>>s;
    cout<<"ENTER THE NUMBER OF FOOD YOU BUY  : ";
    int n; cin>>n;
    cout<<"ENTER THE NUMBER OF FOOD YOU PAY EAXH DAY : ";
    int m; cin>>m;

    int ans = minimumDays(s,n,m);
    cout<<ans;
}