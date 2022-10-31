#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>cost={1,100,1,1,1,100,1,1,100,1};
    int n=cost.size();
    vector<int>dp(n+2,0);
    dp[0]=cost[0];
    dp[1]=cost[1];
    for (int i = 2; i <n; i++)
    {
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
    }

    
    cout<<min(dp[n-1],dp[n-2]);
    
    return 0;
}