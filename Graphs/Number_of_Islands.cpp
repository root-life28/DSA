#include<bits/stdc++.h>
using namespace std;
bool isOk(int n,int m,int i,int j)
{
    if(i<n&&j<m&&i>=0&&j>=0) return true;

    return false;
}
void solve(vector<vector<char>>&grid,vector<vector<bool>>&vis,int n,int m,int i,int j)
{

    if(isOk(n,m,i+1,j)&&grid[i+1][j]=='1'&&vis[i+1][j]==false)
    {
        vis[i+1][j]=true;
        solve(grid,vis,n,m,i+1,j);
    }

    if(isOk(n,m,i,j+1)&&grid[i][j+1]=='1'&&vis[i][j+1]==false)
    {
        vis[i][j+1]=true;
        solve(grid,vis,n,m,i,j+1);
    }

    if(isOk(n,m,i-1,j)&&grid[i-1][j]=='1'&&vis[i-1][j]==false)
    {
        vis[i-1][j]=true;
        solve(grid,vis,n,m,i-1,j);

    }

    if(isOk(n,m,i,j-1)&&grid[i][j-1]=='1'&&vis[i][j-1]==false)
    {
        vis[i][j-1]=true;
        solve(grid,vis,n,m,i,j-1);
    }


}

int main()
{
    vector<vector<char>>grid={
    {'1','1','1','1','0'},
    {'1','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','1','0'}};

    int n=grid.size();
    int m=grid[0].size();
   vector<vector<bool>> vis(n,vector<bool>(m,0));
    int count=0;
    for (int  i = 0; i < n; i++)
    {
        for (int j = 0; j <m; j++)
        {
            if(grid[i][j]=='1'&&vis[i][j]==false)
            {
                vis[i][j]=true;
              
                solve(grid,vis,n,m,i,j);
                count++;
            }
            
        }
        
    }

    cout<<count<<endl;
    
    return 0;
}