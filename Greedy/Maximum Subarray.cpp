#include<bits/stdc++.h>
using namespace std;
// recursive approach
int rec(vector<int>&nums,int i,int take,vector<vector<int>>&dp)
{
    if(i == nums.size()) return take ? 0 : -1e5;  
        if(dp[i][take]!=INT_MIN) return dp[i][take];     
        if(take)
            return dp[i][take]= max(0,nums[i]+rec(nums,i+1,1,dp));                  // either stop here or choose current element nums[i]nd recurse
        return dp[i][take]= max(rec(nums, i+1, 0,dp), nums[i] + rec(nums, i+1, true,dp));
}
// divide and conquer
int solve (vector<int>&nums,int left,int right)
{
    if(left>right) return INT_MIN;
    int mid=(left+right)/2;
    int curr=0;
    int leftBest=0;
    int rightBest=0;

    for (int i =mid-1; i>=left; i--)
    {
        curr+=nums[i];
        leftBest=max(leftBest,curr);
    }

    curr=0;
    for (int i =mid+1; i <=right; i++)
    {
        curr+=nums[i];
        rightBest=max(rightBest,curr);
    }
    
    int bestCombination=nums[mid]+leftBest+rightBest;

    int leftHalf=solve(nums,left,mid-1);
    int rightHalf=solve(nums,mid+1,right);

    return max(bestCombination,max(leftHalf,rightHalf));
    
}

int main()
{
    vector<int>nums={-1,-2};
    int temp=nums[0];
    int mx=nums[0];
    for (int i = 1; i <nums.size(); i++)
    {
       temp=max(nums[i],nums[i]+temp);
        mx=max(temp,mx);
    }
  
    cout<<mx<<endl;

    cout<<solve(nums,0,nums.size()-1)<<endl;
    vector<vector<int>>dp(nums.size()+1,vector<int>(2,INT_MIN));
    cout<<rec(nums,0,0,dp);

    return 0;
}