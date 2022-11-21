#include<bits/stdc++.h>
using namespace std;
// recursive
int solve(string &word1,string &word2,int i,int j,vector<vector<int>>&dp)
{
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if(word1[i]==word2[j]) return dp[i][j]=0+solve(word1,word2,i-1,j-1,dp);
    else {
        ans= min(1+solve(word1,word2,i,j-1,dp),
        min(1+solve(word1,word2,i-1,j,dp),1+solve(word1,word2,i-1,j-1,dp)));
    }  
 
    return dp[i][j]= ans;
}
int main()
{
    string word1="spartan";
    string word2="part";
    int m=word1.length();
     int n=word2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
   // cout<<solve(word1,word2,n,m,dp);

    //bottom up;
        int k = max(m,n);
        vector<int> prev(k+1,0),cur(k+1,0);
         //Base cases for exhaustion of str1 and str2
         for(int j=0;j<=n;j++){
             prev[j] = j;
         }
        for(int i=1;i<=m;i++){
            cur[0]=i;
            for(int j=1;j<=n;j++){

               if(word1[i-1]==word2[j-1]){

                   cur[j]=prev[j-1];
               }
               else{
                   cur[j]= 1 + min(prev[j-1],min(prev[j],cur[j-1]));
               }
            }
            prev = cur;
        }
       cout<< prev[n];
 
    
    return 0;
}