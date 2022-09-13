#include<bits/stdc++.h>
using namespace std;

 int lastStoneWeight(vector<int>&stones)
 {
    priority_queue<int,vector<int>>pq;
    for(auto x:stones)pq.push(x);

    while (pq.size()>1)
    {
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        if(x!=y)pq.push(x-y);
    }

    return pq.size()?pq.top():0;

 }


int main()
{
    vector<int>nums={};

    cout<<lastStoneWeight(nums)<<endl;
    return 0;
}