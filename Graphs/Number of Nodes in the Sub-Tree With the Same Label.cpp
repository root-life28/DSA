#include<bits/stdc++.h>
using namespace std;
vector<int>solve(int node, int parent,vector<vector<int>>&adj,vector<int>&ans,string &label)
{
    vector<int>nodeCnt(26);
    nodeCnt[label[node]-'a']=1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if(adj[node][i]==parent)continue;
        
        vector<int>ch=solve(adj[node][i],node,adj,ans,label);

        for (int i = 0; i < 26; i++)
        {
            nodeCnt[i]+=ch[i];
        }
        
    }

    ans[node] = nodeCnt[label[node] - 'a'];

    return nodeCnt;
    
}

int main()
{
    vector<vector<int>>edges={{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    string labels="abaedcd";
    int n=7;

    vector<vector<int>>adj(n);
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int>ans(n,0);

    solve(0,-1,adj,ans,labels);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i];
    }
    
    
    return 0;
}