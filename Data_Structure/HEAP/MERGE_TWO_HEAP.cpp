#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &a,int n,int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && a[largest] < a[left])
    {
        largest = left;
    }

    if(right < n && a[largest] < a[right])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> a;

    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a.push_back(x);
    }

    int m;
    cin>>m;
    vector<int> b;

    for(int i=0;i<m;i++)
    {
        int x; cin>>x;
        b.push_back(x);
    }

    vector<int> c;

    for(auto i : a)
    {
        c.push_back(i);
    }

    for(auto i : b)
    {
        c.push_back(i);
    }

    int size = c.size();

    for(int i=(size/2)-1;i>=0;i--)
    {
        heapify(c,size,i);
    }

    for(auto i : c)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}