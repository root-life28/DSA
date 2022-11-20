#include<bits/stdc++.h>
using namespace std;
int solve(string &word1,string &word2,int i,int j,vector<vector<int>>&dp)
{
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if(word1[i]==word2[j]) return dp[i][j]=0+solve(word1,word2,i-1,j-1,dp);
    else {
        ans= min(1+solve(word1,word2,i,j-1,dp),min(1+solve(word1,word2,i-1,j,dp),1+solve(word1,word2,i-1,j-1,dp)));
    }  
 
    return dp[i][j]= ans;
}
int main()
{
    string word1="intention";
    string word2="execution";
    vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
    cout<<solve(word1,word2,word1.length(),word2.length(),dp);
    return 0;
}