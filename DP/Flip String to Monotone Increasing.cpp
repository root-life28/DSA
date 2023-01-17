#include<bits/stdc++.h>
using namespace std;
//DP
int solve(int i,string &s,char pre,vector<vector<int>>&dp)
{
    if(i==s.size()) return 0;
    if(dp[i][pre-'0']!=-1) return dp[i][pre-'0'];
    int flip=1000000;
    int not_Flip=1000000;
    if(s[i]=='0')
    {
        if(pre=='0')
        {
            flip=1+solve(i+1,s,'1',dp);
            not_Flip=solve(i+1,s,'0',dp);
        }
        else
        {
            flip=1+solve(i+1,s,'1',dp);
        }
    }
    else 
    {
        if(pre=='0')
        {
            flip=1+solve(i+1,s,'0',dp);
            not_Flip=solve(i+1,s,'1',dp);
        }
        else
        {
           
            not_Flip=solve(i+1,s,'1',dp);
        }
    }

    return dp[i][pre-'0']=min(flip,not_Flip);
}

int main()
{
    string s="100000001010000";
    vector<vector<int>>dp(s.size()+1,vector<int>(2,-1));
    //DP 
    cout<<solve(0,s,'0',dp);
    //simple solution

    int flip=0,flip_one=0;
    for(auto i:s)
    {
        if(i=='1')
        {
            flip_one++;
        }
        else
        {
            flip++;
            flip=min(flip,flip_one);
        }
    }
cout<<flip<<endl;


    return 0;
}