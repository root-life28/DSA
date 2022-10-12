#include<bits/stdc++.h>
using namespace std;

bool isOK(int i,int j,int n,int m,vector<vector<bool>>&vis)
{
   if(i>=n|j>=m||i<0|j<0||vis[i][j])return false;

   vis[i][j]=true;
   return true;
}

int xm=0;

void solve(vector<vector<int>>&grid,vector<vector<bool>>&vis,int n,int m,queue<pair<int,int>>&q)
{
    while (!q.empty())
    {
        int size=q.size();
        xm++;
        for (int k = 0; k < size; k++)
        {
                auto x=q.front();
                q.pop();
                int i=x.first;
                int j=x.second;
                grid[i][j]=2;

            if(isOK(i+1,j,n,m,vis)&&grid[i+1][j]==1)
            {
                q.push({i+1,j});
            }
             if(isOK(i,j+1,n,m,vis)&&grid[i][j+1]==1)
            {
                q.push({i,j+1});
            }
             if(isOK(i-1,j,n,m,vis)&&grid[i-1][j]==1)
            {
                q.push({i-1,j});
            }
             if(isOK(i,j-1,n,m,vis)&&grid[i][j-1]==1)
            {
                q.push({i,j-1});
            }
        }

        
    }
    
}

int main()
{
    vector<vector<int>>grid={
    {2,2},{1,1},{0,0},{2,0}};

    int n=grid.size();
    int m=grid[0].size();
    vector<vector<bool>>vis(n,vector<bool>(m,0));

    queue<pair<int,int>>q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <m; j++)
        {
            if(grid[i][j]==2)
            q.push({i,j});
        }
        
    }

    solve(grid,vis,n,m,q);


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <m; j++)if(grid[i][j]==1) { cout<< -1; return 0;}
        
    }

    cout<<(xm>0?xm-1:xm);


    
    
 return 0;
}