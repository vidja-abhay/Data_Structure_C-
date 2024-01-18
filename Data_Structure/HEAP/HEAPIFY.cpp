#include <bits/stdc++.h>
using namespace std;

void maxheap(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[largest] < a[left])
    {
        largest = left;
    }

    if (right < n && a[largest] < a[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(a[largest], a[i]);
        maxheap(a, n, largest);
    }
}

void minheap(int a[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[smallest] > a[left])
    {
        smallest = left;
    }

    if (right < n && a[smallest] > a[right])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(a[smallest], a[i]);
        minheap(a, n, smallest);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // int m = n - 1;

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxheap(a, n, i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    int m;
    cin >> m;
    int b[m];

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    for (int i = m / 2 - 1; i >= 0; i--)
    {
        minheap(b, m, i);
    }

    for (int i = 0; i < m; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
}