#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>nums={1,2,3,1};
    int n=nums.size();
    if(n==1) return nums[0];
    vector<int>dp(n+2,0);
    dp[0]=nums[0];
    dp[1]=max(dp[0],nums[1]);
    if(n==2) return dp[1];
    dp[2]=dp[0]+nums[2];
    
    for (int i = 3; i <n; i++)
    {
        dp[i]=max(dp[i-2],dp[i-3])+nums[i];
       
    }

    cout<<max(dp[n-1],dp[n-2]);
    


    return 0;
}