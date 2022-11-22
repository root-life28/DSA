#include<bits/stdc++.h>
using namespace std;
int solve(string &s,string &t,int i,int j, vector<vector<int>>&dp)
{   
   if(j==t.length()) return 1;
   if(i==s.length()) return 0;
   if(dp[i][j]!=-1) return dp[i][j];
    int a=0,b=0;
   if(s[i]==t[j])
   {
    a=solve(s,t,i+1,j+1,dp)+solve(s,t,i+1,j,dp);
   }
   else b=solve(s,t,i+1,j,dp);
   
    return dp[i][j]= a+b;
}
int main()
{
    string s="babgbag";
    string t="bag";

    vector<vector<int>>dp(s.length()+1,vector<int>(t.length()+1,-1));
   
    cout<<solve(s,t,0,0,dp);
    return 0;
}