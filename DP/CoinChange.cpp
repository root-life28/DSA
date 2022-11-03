#include<bits/stdc++.h>
using namespace std;


int main()
{
    int amount=9864;
    vector<int>coins={411,412,413,414,415,416,417,418,419,420,421,422};
    
    vector<int>dp(amount+1,INT_MAX-1);

    dp[0]=0;
    
    for (int i = 0; i <coins.size(); i++)
    {
        for (int j =1; j <=amount; j++)
        {
            if(j>=coins[i])
            {
              dp[j] =min(dp[j-coins[i]]+1,dp[j]);
            }

        }
    }

   if(dp[amount]==INT_MAX-1) cout<<-1<<endl;
   else cout<<dp[amount]<<endl;
    


    return 0;
}