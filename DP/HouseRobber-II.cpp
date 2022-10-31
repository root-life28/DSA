#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>nums={200,3,140,20,10};
     int n=nums.size();
    vector<int>dp(n+2,0);
        dp[0]=nums[0];
        if(n==1) return nums[0];
        else if(n==2)cout<< max(nums[0],nums[1]);
        else if(n==3)cout<< max(nums[0],max(nums[1],nums[2]));
        else {
        dp[1]=nums[1];
        dp[2]=nums[2]+dp[0];

        
        for (int i = 3; i <n-1; i++)
        {
            dp[i]=max(dp[i-2],dp[i-3])+nums[i];
        
        }
       int temp=max(dp[n-2],dp[n-3]);
        dp[0]=0;
        dp[1]=nums[1];
        dp[2]=nums[2]+dp[0];
        
    
        for (int i = 3; i <n; i++)
        {
            dp[i]=max(dp[i-2],dp[i-3])+nums[i];
        
        }

        cout<<max(temp,dp[n-1]);
        }
    


    return 0;
}