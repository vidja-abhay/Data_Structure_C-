#include<bits/stdc++.h>
using namespace std;

bool IsSafe(int newx,int newy,vector<vector<bool>> & visited,vector<vector<int>> & a,int n)
{
    if((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && visited[newx][newy] != 1 && a[newx][newy] ==1)
    {
        return true;
    }

    else
    {
        return false;
    }
}

void solve(int x,int y,vector<vector<int>> & a,int n,vector<string> &ans,vector<vector<bool>> & visited,string path)
{
    // base case
    if(x == n-1 && y == n-1)
    {
        ans.push_back(path);
        ans.push_back(" ");
        return;
    }

    // 4 movement [D,L,R,U]

    visited[x][y] = 1;

    // down
    if(IsSafe(x+1,y,visited,a,n))
    {
        visited[x][y] == 1;
        solve(x+1,y,a,n,ans,visited,path + 'D');
    }

    // left
    if(IsSafe(x,y-1,visited,a,n))
    {
        visited[x][y] == 1;
        solve(x,y-1,a,n,ans,visited,path + 'L');
    }

    // right
    if(IsSafe(x,y+1,visited,a,n))
    {
        visited[x][y] == 1;
        solve(x,y+1,a,n,ans,visited,path + 'R');
    }

    // up
    if(IsSafe(x-1,y,visited,a,n))
    {
        visited[x][y] == 1;
        solve(x-1,y,a,n,ans,visited,path + 'L');
    }

    visited[x][y] = 0;
}

vector<string> SearchMaze(vector<vector<int>> & a,int n)
{
    vector<string> ans;
    vector<vector<bool>> visited (n,vector<bool>(n,0));
    string path = "";

    if(a[0][0] == 0)
    {
        return ans;
    }

    solve(0,0,a,n,ans,visited,path);

    return ans;
}

int main()
{
    int n; cin>>n;
    vector<vector<int>> a (n,vector<int>(n,0));

    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            cin>>a[i][j];
        }
    }

    vector<string> ans = SearchMaze(a,n);

    for( auto i : ans)
    {
        cout<<i;
    }
}