#include<bits/stdc++.h>
using namespace std;

void addsolution(vector<vector<int>> &ans,vector<vector<int>> &board,int n)
{
    vector<int> temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp.push_back(board[i][j]);
        }
    }

    ans.push_back(temp);
}

bool IsSafe(int row,int col,vector<vector<int>> &board,int n)
{
    int x = row;
    int y = col;

    // check for same row
    while(y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }

        y--;
    }

    x=row;
    y=col;

    // check for diagonal
    while(x>=0 && y>=0)
    {
        if(board[x][y] == 1)
        {
            return false;
        }
        y--;
        x--;
    }

    x=row;
    y=col;

    // check for diagonal
    while(x<n && y>=0)
    {
        if(board[x][y] == 1)
        {
            return false;
        }
        y--;
        x++;
    }

    return true;
}

void solve(int col,vector<vector<int>> &ans,vector<vector<int>> &board,int n)
{
    // base case
    if(col == n)
    {
        addsolution(ans,board,n);
        return;
    }

    // solve 1 case & rest recursion will take

    for(int row=0;row<n;row++)
    {
        if(IsSafe(row,col,board,n))
        {
            board[row][col] = 1;
            solve(col+1,ans,board,n);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueen(int n)
{
    vector<vector<int>> board (n,vector<int>(n,0));
    vector<vector<int>> ans;

    solve(0,ans,board,n);

    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<vector<int>> ans = nQueen(n);

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
            if((j+1)%n==0)
            {
                cout<<endl;
            }
        }
        cout<<endl;
        cout<<endl;
    }

}