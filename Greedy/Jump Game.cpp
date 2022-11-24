#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int>&nums,int n,int i,bool &a,vector<int>&dp)
{   
    if(i>=nums.size()-1) return true;
    if(dp[i]!=-1) return dp[i];

 for (int j = 0; j <n; j++)
 {
    if(solve(nums,nums[i-j],i-j+nums[i-j],a,dp));
    {
        dp[i]=true;
        return true;
    }
 }
    dp[i]=false;
return false;
}
int main()
{
    vector<int>nums={5,9,3,2,1,0,2,3,3,1,0,0};
    int n=nums.size();
    bool a=false;
    vector<int>dp(n+10,-1);

    cout<<solve(nums,nums[0],nums[0],a,dp)<<endl;

    for (int i = 1; i <=13; i++)
    {
        cout<<dp[i]<<" "<<i<<endl;
    }
    
    
    return 0;
}