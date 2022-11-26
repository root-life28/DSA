#include<bits/stdc++.h>
using namespace std;
struct  Profit{
    int eT;
    int sT;
    int P;
};


int solve(vector<struct Profit>&st,int i,int end,vector<int>&dp)
{
    if(i==st.size()) return 0;
    if(dp[i]!=0) return dp[i];

    int a=0,b=0;
    if(st[i].sT<end)
    {
        return  0+solve(st,i+1,end,dp);
    }
  else {
        a=st[i].P+solve(st,i+1,st[i].eT,dp);
        b=0+solve(st,i+1,end,dp);
        }
    


    return dp[i]= max(a,b);
   
}
int main()
{
    vector<int>startTime={4,2,4,8,2};
    vector<int>endTime={5,5,5,10,8};
    vector<int>profit={1,2,8,10,4};
    
    
    vector<int>dp(startTime.size()+1,0);
    vector<struct Profit>st(startTime.size());
    for (int i = 0; i <startTime.size() ; i++)
    {
        st[i].eT=endTime[i];
        st[i].sT=startTime[i];
        st[i].P=profit[i];
    }

     sort(st.begin(),st.end(),[](const Profit &a, const Profit &b){return a.sT<b.sT;});
      cout<<solve(st,0,0,dp)<<endl;

 
  

    return 0;
}