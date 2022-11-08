#include<bits/stdc++.h>
using namespace std;
//recursive approach
bool solve(int k,int n,vector<int>&nums,vector<vector<int>>&dp)
{
    if(k==0) return true;
    if(n==0) return nums[0]==k;
    if(dp[n][k]!=-1) return dp[n][k];
    bool a=solve(k,n-1,nums,dp);
    bool b=false;

    if(nums[n]<=k)
    {
        b=solve(k-nums[n],n-1,nums,dp);
    }

    return dp[n][k]= a or b;
}

int main()
{
    //vector<int>nums={100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,99,97};
    vector<int>nums={2,3,5};
    int total=accumulate(nums.begin(),nums.end(),0);
    int n=nums.size();
    
    //tabular dp
    vector<vector<int>>table(n+2,vector<int>(13,0));
    table[0][0]=1;
    for (int i =1; i <=nums.size(); i++)
    {
        table[i][0]=1;
    }
    
    
    for (int i = 1; i <=n; i++)
    {
        for (int j =1; j <=13; j++)
        {
            if(j>=nums[i-1])
            {
                if(table[i-1][j-nums[i-1]]) 
                  table[i][j]=1;

                else table[i][j]=table[i-1][j];

            }
            else  table[i][j]=table[i-1][j];
        }
        
    }
    
  
    

    // recursive call
    // if(total%2) cout<<-1<<endl;
    // else {
    //         vector<vector<int>>dp(n,vector<int>(total/2+1,-1));
    //         cout<< solve(total/2,n-1,nums,dp);
    // }



    return 0;
}