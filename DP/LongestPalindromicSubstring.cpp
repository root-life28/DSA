#include<bits/stdc++.h>
using namespace std;

int main()
{
    string  s="dbd";
    int n=s.length();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    int x=0,y=0;
    for (int i = 0; i <n; i++)
    {
        dp[i][i]=1;
        if(i+1<n&&s[i]==s[i+1])
        {
            dp[i][i+1]=1;
            y=i+1;
            x=i;
        }
    }
    

    for (int i = 2; i <n; i++)
    {
        for (int j = 0; j+1<n&&j+i<n; j ++)
        {
            
           if(s[j]==s[j+i]&&dp[j+1][j+i-1])
           {
                dp[j][i+j]=1;
                if(i+j-j>y-x)
                {
                    y=j+i;
                    x=j;
                }
           }
        }
        
    }
    

    cout<<s.substr(x,y-x+1)<<endl;
    

    return 0;
}