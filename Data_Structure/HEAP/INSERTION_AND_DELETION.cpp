#include<bits/stdc++.h>
using namespace std;

class heap        
{
    public : 

    int arr[100];
    int size = 0;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int data)
    {
        size = size + 1;
        int index = size;
        arr[index] = data;

        while(index > 1)
        {
            int parent = index/2;

            if(arr[parent] < arr[index])         // [ < -> max heap & > -> min heap ]
            {
                swap(arr[parent],arr[index]);
                index = parent;
            }

            else
            {
                return;
            }
        }
    }

    void dlt()
    {
        if(size == 0)
        {
            cout<<"NOTHING TO DELETE !"<<endl;
            return;
        }

        // step 1 : put last element into 1st index
        arr[1] = arr[size];

        // step 2 : remove last element
        size--;


        // step 3 : take root node to its correct position
        int i = 1;
        while(i < size)
        {
            int left = 2*i;
            int right = 2*i + 1;

            if(left < size && arr[i] < arr[left])      // [ < -> max heap & > -> min heap ]
            {
                swap(arr[i],arr[left]);
                i = left;
            }

            else if(right < size && arr[i] < arr[right])      // [ < -> max heap & > -> min heap ]
            {
                swap(arr[i],arr[right]);
                i = right;
            }

            else
            {
                return;
            }
        }
    }

    void print()
    {
        for(int i=1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.dlt();

    h.print();

    return 0;
}