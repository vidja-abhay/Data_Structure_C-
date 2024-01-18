// JOB SEQUENCE PROBLEM
// GREEK FOR GREEKS

#include<bits/stdc++.h>
using namespace std;

struct job
{
    int job_id;
    int deadline;
    int profit;
};

static bool cmp(job a,job b)
{
    return a.profit > b.profit;
}

vector<int> solve(int n,job a[])
{
    sort(a,a+n,cmp);

    int max_deadline = INT_MIN;
    for(int i=0;i<n;i++)
    {
        max_deadline = max(max_deadline,a[i].deadline);
    }

    vector<int> schedule(max_deadline + 1,-1);

    int count = 0;
    int max_profit = 0;

    for(int i=0;i<n;i++)
    {
        int cur_profit = a[i].profit;
        int cur_deadlin = a[i].deadline;
        int cur_jobid = a[i].job_id;

        for(int k=cur_deadlin;k>0;k--)
        {
            if(schedule[k] == -1)
            {
                count++;
                max_profit += cur_profit;
                schedule[k] = cur_jobid;
                break;
            }
        }
    }

    vector<int> ans;
    ans.push_back(count);
    ans.push_back(max_profit);

    return ans;
}

int main()
{
    int n; cin>>n;

    job a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i].job_id;
        cin>>a[i].deadline;
        cin>>a[i].profit;
    }

    vector<int> ans = solve(n,a);

    for(auto i : ans)
    {
        cout<<i<<" ";
    }
}