#include<bits/stdc++.h>
using namespace std;

bool isOk(int n,int m,int i,int j)
{
    if(i<n&&j<m&&i>=0&&j>=0) return true;

    return false;
}

void solve(vector<vector<int>>&grid,vector<vector<bool>>&vis,int n,int m,int i,int j,int &mx)
{
    if(isOk(n,m,i,j)==false) return;
    mx+=1;
    vis[i][j]=true;
    if(isOk(n,m,i+1,j)&&grid[i+1][j]&&vis[i+1][j]==false)
    {
        solve(grid,vis,n,m,i+1,j,mx);
    }

    if(isOk(n,m,i,j+1)&&grid[i][j+1]&&vis[i][j+1]==false)
    {
        solve(grid,vis,n,m,i,j+1,mx);
    }

    if(isOk(n,m,i-1,j)&&grid[i-1][j]&&vis[i-1][j]==false)
    {
        solve(grid,vis,n,m,i-1,j,mx);
    }

    if(isOk(n,m,i,j-1)&&grid[i][j-1]&&vis[i][j-1]==false)
    {
        solve(grid,vis,n,m,i,j-1,mx);
    }



}

int main()
{
     vector<vector<int>>grid={
    {0,0,1,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };

    int n=grid.size();
    int m=grid[0].size();
    int cnt=0;
    int mx=0;

    vector<vector<bool>>vis(n,vector<bool>(m,0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(grid[i][j]==1&&vis[i][j]==false)
            {
                cnt=0;
                solve(grid,vis,n,m,i,j,cnt);

                mx=max(cnt,mx);
                
            }
           
        }
        
    }

    cout<<mx<<endl;
    
}