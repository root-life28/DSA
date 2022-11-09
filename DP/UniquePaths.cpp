#include<bits/stdc++.h>
using namespace std;
int temp[101][101]={0};
//recursive approach
int solve(int i,int j,int m,int n)
{
  if(i>=m||j>=n) return 0;
  if(i==m-1&&j==n-1) return 1;
  if(temp[i][j]) return temp[i][j];
  int a=0,b=0;
  a=solve(i+1,j,m,n);
  b=solve(i,j+1,m,n);

  return temp[i][j]=a+b;
}

int main()
{
    int m=3;
    int n=7;
  // Bottom -up approach
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
 //recursive call
  cout<<solve(0,0,m,n);

    return 0;
}