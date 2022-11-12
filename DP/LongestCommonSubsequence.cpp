#include<bits/stdc++.h>
using namespace std;
// recursive approach
int solve(string &text1,string &text2,int i,int j,int n,int m,vector<vector<int>>&dp)
{
    if(i==n||j==m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

     int a=0,b=0;
    if(text1[i]==text2[j])
    return dp[i][j]=1+solve(text1,text2,i+1,j+1,n,m,dp);
    else
    {
        a=solve(text1,text2,i+1,j,n,m,dp);
        b=solve(text1,text2,i,j+1,n,m,dp);
    }
  
return dp[i][j]=max(a,b);
    
}
int main()
{
    string text1="ABCBDAB";
    string text2="BDCABA";
    int n=text1.size();
    int m=text2.size();
    vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
    cout<<solve(text1,text2,0,0,n,m,dp)<<endl;

    //Bottom up approach

    vector<vector<int>>dp1(n+2,vector<int>(m+2,0));
    for (int i = 1; i <=n; i++)
    {
        for (int j =1; j <=m; j++)
        {
            if(text1[i-1]==text2[j-1])
            {
                dp1[i][j]=dp1[i-1][j-1]+1;
            }
            else {
                dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1]);
            }
        }        
    }

    cout<<dp1[n][m];
    

    return 0;
}