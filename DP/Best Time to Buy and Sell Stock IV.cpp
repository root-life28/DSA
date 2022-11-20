#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&prices,int i,int buy,int n,int k, vector<vector<vector<int>>>&dp)
{
    if(i==n||k==0) return 0;
    if(dp[i][buy][k]!=-1) return dp[i][buy][k];
    int profit=0;
    if(buy)
    {
            profit=max(-prices[i]+solve(prices,i+1,0,n,k,dp),0+solve(prices,i+1,1,n,k,dp));
    }
    else 
    {
        profit=max(prices[i]+solve(prices,i,1,n,k-1,dp),0+solve(prices,i+1,0,n,k,dp));
    }

    return dp[i][buy][k]= profit;
}
int main()
{
    vector<int>prices={3,2,6,5,0,3};
    int k=2;
    int n=prices.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
    cout<<solve(prices,0,1,n,k,dp);
    return 0;
}