#include<bits/stdc++.h>
using namespace std;

void DFS(int i,vector<vector<int>> &adj, unordered_set<int>&vis)
{
    vis.insert(i);
    for(auto x:adj[i])
    {
        if(vis.find(x)==vis.end())
        {
            DFS(x,adj,vis);
        }
    }
}

int solve(vector<vector<int>>& bs)
{
       int res = 0, sz = bs.size();
    vector<vector<int>> al(bs.size());
    for (int i = 0; i < sz; ++i) {
        long long x = bs[i][0], y = bs[i][1], r2 = (long long)bs[i][2] * bs[i][2];
        for (int j = 0; j < bs.size(); ++j)
            if ((x - bs[j][0]) * (x - bs[j][0]) + (y - bs[j][1]) * (y - bs[j][1]) <= r2)
                al[i].push_back(j);
    }


    unordered_set<int>vis;
    for(int i=0;i<bs.size();i++)
    {
        DFS(i,al,vis);

        res=max(res,(int)vis.size());
        vis.clear();

    }
    return res;
}

int main()
{
    vector<vector<int>>booms={{2,1,3},{6,1,4}};

    cout<<solve(booms);
    return 0;
}