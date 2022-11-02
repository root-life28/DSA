#include<bits/stdc++.h>
using namespace std;


int solve(string &s,int i,unordered_map<int,int>&mp,vector<int>&dp)
{
  
    if(i>=s.length())
    {
        return 1;
    }
   if(dp[i])return dp[i];
    if(s[i]=='0') return 0;
    int x=0, y=0;
    x=solve(s,i+1,mp,dp);
   
    if(i+1<s.length()){
        int m=(s[i]-'0')*10;
        int n=s[i+1]-'0';
        if(m&&mp[m+n]){
        y=solve(s,i+2,mp,dp);
        }
    }


  return dp[i]=x+y;
}

int main()
{
    string s="111111111111111111";
    vector<int>dp(s.size()+1,0);
    unordered_map<int ,int>mp;
    for (int i = 1; i <=26; i++)
    {
        mp[i]=1;
    }


    cout<<solve(s,0,mp,dp);

   
    

 
    

    return 0;
}