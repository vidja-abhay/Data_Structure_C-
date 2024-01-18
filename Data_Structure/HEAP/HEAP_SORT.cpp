#include<bits/stdc++.h>
using namespace std;

void maxheap(int a[],int n,int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && a[left] > a[largest])
    {
        largest = left;
    }

    if(right < n && a[right] > a[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(a[largest],a[i]);
        maxheap(a,n,largest);
    }
}

void sort(int a[],int n)
{
    int size = n;

    while(size > 1)
    {
        swap(a[0],a[size-1]);

        size--;

        maxheap(a,size,0);
    }
}

int main()
{
    int n; cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=n/2-1;i>=0;i--)
    {
        maxheap(a,n,i);
    }

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    sort(a,n);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}