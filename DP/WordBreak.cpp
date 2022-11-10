#include<bits/stdc++.h>
using namespace std;
// recursion & memoization 
bool solve(string &s,set<string>&st,int start,vector<int>&dp)
{
    if(start==s.length()) return true;
    if(dp[start]!=-1) return dp[start];
    for (int i =start+1; i <=s.length(); i++)
    {
        if(st.find(s.substr(start,i-start))!=st.end()&&solve(s,st,i,dp))
        {
            return dp[start]=true;
        }
    }
    return dp[start]=false;
}
int main()
{
    string s="leetcode";
    vector<string>wordDict={"leet","code"};

    // recursive call;
    set<string>st(wordDict.begin(),wordDict.end());
    vector<int>dp(300+2,-1);
    cout<<solve(s,st,0,dp)<<endl;

    


    return 0;
}