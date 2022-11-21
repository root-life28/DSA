#include<bits/stdc++.h>
using namespace std;
bool solve(string &s1,string &s2,string &s3,int i,int j,int k,vector<vector<int>>&dp)
{
   if(s3.length()==k&&i==s1.length()&&j==s2.length()) return true;


   if(dp[i][j]!=-1)return dp[i][j];


    if(i<s1.length()&&j<s2.length()&&k<s3.length()&&s1[i]==s3[k]&&s2[j]==s3[k])
    {
      return dp[i][j]=solve(s1,s2,s3,i+1,j,k+1,dp)||solve(s1,s2,s3,i,j+1,k+1,dp);
    }
    else if(i<s1.length()&&k<s3.length()&&s1[i]==s3[k])
    {
      return solve(s1,s2,s3,i+1,j,k+1,dp);
    }

    else if(j<s2.length()&&k<s3.length()&&s2[j]==s3[k])
    {
      return solve(s1,s2,s3,i,j+1,k+1,dp);
    }
    else return false;
}

int main()
{
    string s1="aabcc";
    string s2="dbbca";
    string s3="aadbbcbcac";
   vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,-1));
    cout<<solve(s1,s2,s3,0,0,0,dp);
    return 0;
}