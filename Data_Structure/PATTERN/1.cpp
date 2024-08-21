#include <bits/stdc++.h>
using namespace std;


void pattern21(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << " " << " ";
        }

        for (int j = 1; j <= n; j++)
        {
            cout << '*' << " ";
        }

        cout << endl;
    }

    //         * * * * *
    //       * * * * *
    //     * * * * *
    //   * * * * *
    // * * * * *
}

void pattern22(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << " " << " ";
        }

        if (i == 1 || i == n)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << '*' << " ";
            }
        }

        else{
            cout<<'*'<<" ";
            for(int j=1;j<=n-2;j++){
                cout<<" "<<" ";
            }
            cout<<'*'<<" ";
        }

         cout<<endl;
    }

//        * * * * * 
//       *       * 
//     *       * 
//   *       * 
// * * * * * 

   
}

void pattern23(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
        int x =((i+j)%2==0)?1:0;
        cout<< x << " ";

        }
        cout << endl;
    }
// 1 
// 0 1 
// 1 0 1 
// 0 1 0 1 
// 1 0 1 0 1 
}

int main()
{

    pattern23(5);

    return 0;
}