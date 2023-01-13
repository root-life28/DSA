#include<bits/stdc++.h>
using namespace std;
int ans=1;
int dfs(int node,int parent, vector<vector<int>>&adj,string &s)
{
    int large=0;
    int secLarge=0;
    for (auto &child:adj[node])
    {
        if(child==parent)continue;
        int ChildCnt=dfs(child,node,adj,s);
        if(s[child]==s[node])continue;

        if(ChildCnt>secLarge)
        {
            secLarge=ChildCnt;
        }

        if(secLarge>large)
        {
            swap(secLarge,large);
        }

    }

    int l_or_r=max(large,secLarge)+1;
    int root=1;
    int l_r=1+large+secLarge;
    ans=max({ans,l_or_r,root,l_r});


    return max(root,l_or_r);
    
}
int main()
{
    vector<int>parent={-1,0,0,1,1,2};
    string s="abacbe";
    int n=parent.size();
    vector<vector<int>>adj(n);
    for (int i = 1; i < n; i++)
    {
        adj[parent[i]].push_back(i);
        
    }

    dfs(0,-1,adj,s);
    cout<<ans;
    return 0;
}