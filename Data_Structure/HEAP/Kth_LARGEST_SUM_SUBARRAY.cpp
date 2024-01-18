#include<bits/stdc++.h>
using namespace std;

int solve1(vector<int> a,int k)
{
    vector<int> ans;

    int n = a.size();

    for(int i=0;i<n;i++)
    {
        int sum = 0;

        for(int j=i;j<n;j++)
        {
            sum += a[j];
            ans.push_back(sum);
        }
    }

    sort(ans.begin(),ans.end());

    return ans[ans.size() - k];
}

int solve2(vector<int> a,int k)
{
    priority_queue<int,vector<int>,greater<int>> p;

    int n = a.size();

    for(int i=0;i<n;i++)
    {
        int sum = 0;

        for(int j=i;j<n;j++)
        {
            sum += a[j];

            if(p.size() < k)
            {
                p.push(sum);
            }

            else
            {
                if(p.top() < sum)
                {
                    p.pop();
                    p.push(sum);
                }
            }
        }
    }

    return p.top();
}

int main()
{
    int n; cin>>n;

    vector<int> a;

    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a.push_back(x);
    }

    cout<<solve1(a,3)<<endl;

    cout<<solve2(a,3)<<endl;
}