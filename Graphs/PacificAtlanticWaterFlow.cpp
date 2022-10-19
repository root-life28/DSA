#include<bits/stdc++.h>
using namespace std;
bool a=false,b=false;

bool isOK(int i,int j,int n,int m,vector<vector<bool>>&vis)
{
    if(i<0||j<0||i>=n||j>=m||vis[i][j]) return false;
    return true;
}
void dfs(vector<vector<int>>&grid,int i,int j,int n,int m,vector<vector<bool>>&vis)
{
    
    vis[i][j]=true;

    

    if(isOK(i+1,j,n,m,vis)&&grid[i+1][j]>=grid[i][j])
        dfs(grid,i+1,j,n,m,vis);
    
    if(isOK(i,j+1,n,m,vis)&&grid[i][j+1]>=grid[i][j])
        dfs(grid,i,j+1,n,m,vis);

    if(isOK(i-1,j,n,m,vis)&&grid[i-1][j]>=grid[i][j])
        dfs(grid,i-1,j,n,m,vis);

    if(isOK(i,j-1,n,m,vis)&&grid[i][j-1]>=grid[i][j])
        dfs(grid,i,j-1,n,m,vis);

   
}


int main()
{
    //vector<vector<int>>heights={{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>>heights={{1,2,3},{8,9,4},{7,6,5}};

    vector<vector<int>>res;
    int n=heights.size();
    int m=heights[0].size();
    vector<vector<bool>>as(n,vector<bool>(m,0));
    vector<vector<bool>>alt(n,vector<bool>(m,0));

    for (int i = 0; i < n; i++)
    {
        dfs(heights,i,0,n,m,as);
        dfs(heights,i,m-1,n,m,alt);
    }

    for (int i = 0; i < m; i++)
    {
        dfs(heights,0,i,n,m,as);

        dfs(heights,n-1,i,n,m,alt);
    }
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j <m; j++)
        {
            if(as[i][j]&&alt[i][j])res.push_back({i,j});
        }
        
    }
    
   
    return 0;
}