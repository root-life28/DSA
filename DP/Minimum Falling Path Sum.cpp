#include<bits/stdc++.h>
using namespace std;
int solve( vector<vector<int>>&matrix,int i,int j,vector<vector<int>>&dp)
{
    if(i==matrix.size()) return 0;
    if(j<0||j==matrix[0].size()) return INT_MAX;
    if(dp[i][j]!=INT_MAX) return dp[i][j];

    int a=solve(matrix,i+1,j-1,dp);
    int b=solve(matrix,i+1,j,dp);
    int c=solve(matrix,i+1,j+1,dp);

    return dp[i][j]= matrix[i][j]+min({a,b,c});
}

int main()
{
    vector<vector<int>>matrix={{2,1,3},{6,5,4},{7,8,9}};
    
    int mi=INT_MAX;
    vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix[0].size()+1,INT_MAX));
    for (int i = 0; i <matrix[0].size(); i++)
    {
        int x=solve(matrix,0,i,dp);
        mi=min(mi,x);
        
    }


    for (int i = 0; i <matrix.size(); i++)
    {
        for (int j = 0; j <matrix[0].size(); j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}