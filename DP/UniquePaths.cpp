#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m=1;
    int n=2;

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for (int i = 0; i <m; i++)dp[0][i]=1;
    for (int i = 0; i <n; i++)dp[i][0]=1;

    for (int i = 1; i <n; i++)
    {
        for (int j =1; j<m; j++)
        {
            dp[i][j]=(dp[i][j-1]+dp[i-1][j]);
        }
        
    }

  cout<<dp[n-1][m-1]<<endl;
 

    return 0;
}