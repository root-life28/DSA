#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k=3;
    int w=0;
    vector<int>profits={1,2,3};
    vector<int>capital={0,1,1};

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minCapital;
    priority_queue<int>maxProfit;

    for (int i = 0; i < profits.size(); i++)
    {
        minCapital.push({capital[i],profits[i]});
    }

    for (int i = 0; i < k; i++)
    {

        while (!minCapital.empty()&&minCapital.top().first<=w)
        {
            
            auto x=minCapital.top();
            minCapital.pop();
            maxProfit.push(x.second);
        }
        if(!maxProfit.empty()){
        w+=maxProfit.top();
        maxProfit.pop();}
    }

    cout<<w<<endl;
    

    return 0;
}