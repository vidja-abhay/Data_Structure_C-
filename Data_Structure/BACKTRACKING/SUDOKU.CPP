#include<bits/stdc++.h>
using namespace std;

bool IsSafe(int row,int col,vector<vector<int>> &board,int val)
{
    for(int i=0;i<board.size();i++)
    {
        // row check
        if(board[row][i] == val)
        {
            return false;
        }

        // col check
        if(board[i][col] == val)
        {
            return false;
        }

        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val)
        {
            return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>> &board)
{
    int n = board.size();

    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
        {
            // check cell empty
            if(board[row][col] == 0)
            {
                for(int val=1;val<=9;val++)
                {
                    if(IsSafe(row,col,board,val))
                    {
                        board[row][col] = val;

                        // recursive call

                        bool agge = solve(board);

                        if(agge)
                        {
                            return true;
                        }
                        else
                        {
                            // backtrack

                            board[row][col] = 0;
                        }
                    }
                }

                return false;
            }
        }
    }

    return true;
}

void solvesudoku(vector<vector<int>> & a)
{
    solve(a);
}

int main()
{
    vector<vector<int>> a (9,vector<int> (9));

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>a[i][j];
        }
    }

    solvesudoku(a);

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<a[i][j]<<" ";
        }

        cout<<endl;
    }    

}

/*input
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
*/

/*output
3 1 6 5 7 8 4 9 2 
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9
*/