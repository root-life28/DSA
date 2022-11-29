#include<bits/stdc++.h>
using namespace std;
struct  Profit{
    int eT;
    int sT;
    int P;
};


int solve(vector<struct Profit>&st,int i,int end,vector<int>&dp,vector<int>&sta)
{
    if(i==st.size()) return 0;
    if(dp[i]!=0) return dp[i];
    int a=0,b=0;
    // find next position
    auto idx=lower_bound(sta.begin(),sta.end(),st[i].eT)-sta.begin();

        a=st[i].P+solve(st,idx,st[i].eT,dp,sta);
        b=0+solve(st,i+1,end,dp,sta);    


    return dp[i]= max(a,b);
   
}
int main()
{
    vector<int>staTime={4,2,4,8,2};
    vector<int>endTime={5,5,5,10,8};
    vector<int>profit={1,2,8,10,4};
    
    vector<int>dp(staTime.size()+1,0);
    vector<struct Profit>st(staTime.size());
    for (int i = 0; i <staTime.size() ; i++)
    {
        st[i].eT=endTime[i];
        st[i].sT=staTime[i];
        st[i].P=profit[i];
    }

     sort(st.begin(),st.end(),[](const Profit &a, const Profit &b){return a.sT<b.sT;});
     vector<int>sta;
     for (int i = 0; i < st.size(); i++)
     {
        sta.push_back(st[i].sT);
     }

     
      cout<<solve(st,0,0,dp,sta)<<endl;

 
  

    return 0;
}