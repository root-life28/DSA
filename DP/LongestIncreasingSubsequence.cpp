#include<bits/stdc++.h>
using namespace std;

int LIS(int i,vector<int>&nums,vector<int>&dp)
{
    if(dp[i]!=-1) return dp[i];
    int temp=1;
    for (int j = 0; j<i; j++)
    {
        if(nums[i]>nums[j])
        temp=max(temp,LIS(j,nums,dp)+1);
    }
    return dp[i]=temp;
}
int main()
{
    vector<int>nums={10,9,2,5,3,7,101,18};
    int n=nums.size();
    vector<int>dp(n+1,-1);
    int ans=1;
    for (int i = 0; i < n; i++)
    {
        ans=max(ans,LIS(i,nums,dp));
    }

    cout<<ans<<endl;

   
    
    
  
    return 0;
}