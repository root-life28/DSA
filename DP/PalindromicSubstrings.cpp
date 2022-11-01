#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s="aaa";
    int n=s.length();

    int ans =n;
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for (int i = 0; i < n; i++)
    {
        dp[i][i]=1;
        if(i+1<n&&s[i]==s[i+1])
        {
            ans++;
            dp[i][i+1]=1;
        }
    }

    for (int i = 2; i <n; i++)
    {
       for (int j = 0; j+1<n&&j+i<n; j ++)
        {
            if(s[j]==s[j+i]&&dp[j+1][j+i-1])
           {
                dp[j][i+j]=1;
                ans++;
           }
        }
        
    }
    
    cout<<ans;
    


    return 0;
}