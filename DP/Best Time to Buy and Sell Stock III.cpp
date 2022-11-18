#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&prices,int i,int n,int buy,int status,vector<vector<vector<int>>>&dp)
{
    if(n==i)return 0;
    if(status==3) return 0;
    if(dp[i][buy][status]!=-1) return dp[i][buy][status];
    int profit=0;
    if(buy)
    {
        profit=max(-prices[i]+solve(prices,i+1,n,0,status+1,dp),0+solve(prices,i+1,n,1,status,dp));
    }
    else 
    {
        profit=max(prices[i]+solve(prices,i+1,n,1,status,dp),0+solve(prices,i+1,n,0,status,dp));
    }

    return dp[i][buy][status]= profit;
}

int main()
{
    vector<int>prices={3,3,5,0,0,3,1,4};
    int n=prices.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));

    cout<<solve(prices,0,n,1,0,dp);
   
    return 0;
}