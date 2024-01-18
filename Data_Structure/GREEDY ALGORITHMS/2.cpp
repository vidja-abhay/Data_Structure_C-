// SHOP IN CANDY STORE
// GREEK FOR GREEKS

#include<bits/stdc++.h>
using namespace std;

pair<int,int> minmax(int n,int k,vector<int> &candy)
{
    sort(candy.begin(),candy.end());

    int mini = 0;
    int buy = 0;
    int free = n-1;

    while(buy <= free)
    {
        mini += candy[buy];
        buy++;
        free -= k;
    }

    int maxi = 0;
    buy = n-1;
    free = 0;

    while(free <= buy)
    {
        maxi += candy[buy];
        buy--;
        free += k;
    }

    pair<int,int> ans = make_pair(mini,maxi);
    return ans;
}

int main()
{
    cout<<"ENTER THE NUMBER OF CANDY IN SHOP : ";
    int n; cin>>n;
    cout<<"ENTER THE NUMBER OF CANDY WILL GET YOU FREE : ";
    int k; cin>>k;

    vector<int> candy(n);
    for(int i=0;i<n;i++)
    {
        cin>>candy[i];
    } 

    pair<int,int> ans = minmax(n,k,candy);
    cout<<ans.first<<" "<<ans.second<<endl;

}