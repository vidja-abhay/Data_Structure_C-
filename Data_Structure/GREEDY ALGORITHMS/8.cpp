// FRACTIONAL KNAPSACK
// IMP FOR INTERVIEW
// GREEK FOR GREEKS
#include<bits/stdc++.h>
using namespace std;

struct item
{
    int value;
    int weight;
};

static bool cmp(pair<double,item> a,pair<double,item> b)
{
    return a.first > b.first;
}

double fractional(int w,item a[],int n)
{
    vector<pair<double,item>> v;

    for(int i=0;i<n;i++)
    {
        double perUnitVal = (1.0 * a[i].value) / a[i].weight;

        pair<double,item> p = make_pair(perUnitVal,a[i]);

        v.push_back(p);
    }

    sort(v.begin(),v.end(),cmp);

    double totalValue = 0;

    for(int i=0;i<n;i++)
    {
        if(v[i].second.weight > w)
        {
            totalValue += w*v[i].first;
            w = 0;
            // sirf fraction part lene
        }

        else
        {
            totalValue += v[i].second.value;
            w = w - v[i].second.weight;
        }
    }

    return totalValue;
}

int main()
{
    int n;
    cout<<"ENTER THE NUMBER OF VALUE : ";
    cin>>n;

    int w;
    cout<<"ENTER THE CAPACITY OF BAGS : ";
    cin>>w;

    item a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i].value;
    }

    for(int i=0;i<n;i++)
    {
        cin>>a[i].weight;
    }

    double ans = fractional(w,a,n);
    cout<<ans;

    return 0;
}