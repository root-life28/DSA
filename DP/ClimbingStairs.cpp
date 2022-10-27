#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>&dp)
{
    if(dp[n]) return dp[n];
    if(n==0||n==1) return 1;

    return dp[n]=solve(n-1,dp)+solve(n-2,dp);
}

int main()
{
    int n=45;
    vector<int>dp(46,0);

    cout<<solve(n,dp)<<endl;

    // another way
     int temp1=1,temp2=2;
    if (n==1) cout<<temp1<<endl;
    else if(n==2) cout<<temp2<<endl;

    for (int i = 3; i <=n; i++)
    {   int m=(temp1+temp2);
        temp1=temp2;
        temp2=m;
    }

    cout<<temp2<<endl;
    


    return 0;
}