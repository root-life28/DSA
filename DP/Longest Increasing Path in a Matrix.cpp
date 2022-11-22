#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>>&matrix,int i,int j,int n,int m,vector<vector<int>>&dp)
{
    if(dp[i][j]) return dp[i][j];
    int a=1,b=1,c=1,d=1;
    if(j+1<m&&matrix[i][j]<matrix[i][j+1]&&dp[i][j]==0)
    {
        a=1+solve(matrix,i,j+1,n,m,dp);
    }

    if(i+1<n&&matrix[i][j]<matrix[i+1][j]&&dp[i][j]==0)
    {
        b=1+solve(matrix,i+1,j,n,m,dp);
    }

    if(i-1>=0&&matrix[i][j]<matrix[i-1][j]&&dp[i][j]==0)
    {
        c=1+solve(matrix,i-1,j,n,m,dp);
    }
    if(j-1>=0&&matrix[i][j]<matrix[i][j-1]&&dp[i][j]==0)
    {
        d=1+solve(matrix,i,j-1,n,m,dp);
    }

     return dp[i][j]= max(a,max(b,max(c,d)));
}   
int main()
{
    vector<vector<int>>matrix={{9,9,4},{6,6,8},{3,2,1}};
    int n=matrix.size();
    int m=matrix[0].size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    int mx=1;
    for (int i = 0; i <n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if(dp[i][j]==0)
            {
                int x=solve(matrix,i,j,n,m,dp);
                mx=max(mx,x);
            }
        }
        
    }

    cout<<mx;
    
    return 0;
}