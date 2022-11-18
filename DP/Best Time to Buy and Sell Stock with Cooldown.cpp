#include<bits/stdc++.h>
using namespace std;
//recursive
 int solve(vector<int>&prices,int i,int n,int buy,vector<vector<int>>&dp)
 {
    if(i>=n) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    int profit =0;

    if(buy)
    {
        profit=max(-prices[i]+solve(prices,i+1,n,0,dp),0+solve(prices,i+1,n,1,dp));
    }
    else {
        profit=max(prices[i]+solve(prices,i+2,n,1,dp),0+solve(prices,i+1,n,0,dp));
    }

    return dp[i][buy]= profit;
 }

int main()
{
    vector<int>prices={1,2,3,0,2};
    int n=prices.size();
    vector<vector<int>>dp(n+1,vector<int>(2,-1));
    cout<<solve(prices,0,n,1,dp)<<endl;


// bottom -up
    vector<vector<int>>dp1(n+2,vector<int>(2,0));
    for (int i =n-1; i>=0; i--)
    {
        for (int buy = 0; buy <=1; buy++)
        {
             int profit =0;
            if(buy)
              profit =max(-prices[i]+dp1[i+1][0],0+dp1[i+1][1]);
            else{
                profit=max(prices[i]+dp1[i+2][1],0+dp1[i+1][0]);
            }

            dp1[i][buy]= profit;
        }
        
    }

    cout<<dp1[0][1]<<endl;

    
}