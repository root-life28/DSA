#include<bits/stdc++.h>
using namespace std;
// recursive approach
int solve(vector<int>&coins,int i,int amount,vector<vector<int>>&dp)
{
    if(amount==0) return 1;
    if(i==coins.size()) return 0;

    if(dp[i][amount]!=-1) return dp[i][amount];
    int a=0,b=0;
    if(amount>=coins[i])
    a=solve(coins,i,amount-coins[i],dp);
    b=solve(coins,i+1,amount,dp);

    return dp[i][amount]= a+b;
    
}
int main()
{
    vector<int>coins={1,2,5};
    int amount =5;
    vector<vector<int>>dp(coins.size()+2,vector<int>(5001,-1));
    cout<<solve(coins,0,amount,dp);
    // Bottom up
    
    return 0;
}