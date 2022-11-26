#include<bits/stdc++.h>
using namespace std;
int f(int ind, int n, vector<int>& nums, vector<int>& dp) {
    if(ind == n-1) return 0;
    if(dp[ind] != -1) return dp[ind];
    
    int jump = nums[ind], mini = 1e9;
    for(int i = ind + 1; i <= min(ind+jump, n-1); i++) {
        int val = 1 + f(i, n, nums, dp);
        mini = min(mini, val);
    }
    return dp[ind] = mini;
}
int main()
{
    //vector<int>nums={7,8,4,2,0,6,4,1,8,7,1,7,4,1,4,1,2,8,2,7,3,7,8,2,4,4,5,3,5,6,8,5,4,4,7,4,3,4,8,1,1,9,0,8,2};
    vector<int>nums={2,1,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,5,0,0,3,8,2,4,6,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
    vector<int>dp(nums.size()+2,-1);
    cout<<f(0,nums.size(),nums,dp);

    return 0;
}