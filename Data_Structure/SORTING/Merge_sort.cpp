#include<iostream>
using namespace std;

void merge(int a[],int start,int end)
{
    int mid = (start + end)/2;

    int L1 = mid - start + 1;
    int L2 = end - mid;

    int left[L1],right[L2];

    int l = start;
    for(int i=0;i<L1;i++)
    {
        left[i] = a[l++];
    }

    int r=mid+1;
    for(int i=0;i<L2;i++)
    {
        right[i] = a[r++];
    }

    int index1 = 0;
    int index2 = 0;
    int mainindex = start;

    while(index1 < L1 && index2 < L2)
    {
        if(left[index1] < right[index2])
        {
            a[mainindex++] = left[index1++];
        }
        else
        {
            a[mainindex++] = right[index2++];
        }
    }

    while(index1 < L1)
    {
        a[mainindex++] = left[index1++];
    }

    while(index2 < L2)
    {
        a[mainindex++] = right[index2++];
    }
}

void mergesort(int a[],int start,int end)
{
    if(start >= end)
    {
        return;
    }

    int mid = (start + end)/2;

    mergesort(a,start,mid);

    mergesort(a,mid+1,end);

    merge(a,start,end);
}
int main()
{
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}