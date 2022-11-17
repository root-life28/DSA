#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&nums,int i,int target,int sum,vector<vector<int>>&dp)
{
    if(i==nums.size())
    {
        if(sum==target) return 1;
        else return 0;
    }
    if(sum<0)
    {
        if(dp[i][sum+3000]!=INT_MIN) return dp[i][sum+3000];
    }
    else {if(dp[i][sum]!=INT_MIN) return dp[i][sum];}
    
    int a=0,b=0;
    a=solve(nums,i+1,target,sum+nums[i],dp);
    b=solve(nums,i+1,target,sum-nums[i],dp);

    return sum>=0?dp[i][sum]= a+b : dp[i][sum+3000]=a+b;
}

int main()
{
    vector<int>nums={1};
    int target=1;
    vector<vector<int>>dp(nums.size()+2,vector<int>(5000+2,INT_MIN));
    cout<<solve(nums,0,target,0,dp);
    return 0;
}