#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>&vr,int k)
{
    int n=vr.size();
    int sum=0,count=0;
   unordered_map<int,int>mp;
    mp[sum]++;
    for (int i = 0; i <n; i++)
    {
        sum+=vr[i];

        if(mp.find(sum-k)!=mp.end())
        {
            count+=mp[sum-k];
        }
        mp[sum]++;
    }
    
    return count;
}

int main()
{
    vector<int>vr={1,2,3,3,3};

    cout<<solve(vr,3  );
    return 0;
}