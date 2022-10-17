#include<bits/stdc++.h>
using namespace std;
 bool isCyclic(vector<vector<int>>& adj,vector<int>& visited,int curr)
    {
        if(visited[curr]==2)
            return true;
        
        visited[curr] = 2;
        for(int i=0;i<adj[curr].size();++i)
            if(visited[adj[curr][i]]!=1)
                if(isCyclic(adj,visited,adj[curr][i]))
                    return true;
        
        visited[curr] = 1;
        return false;
    }

int main()
{
    int number=2;
    vector<vector<int>>pre={{1,0},{0,1}};

    vector<vector<int>>adj(number);

    for (int i = 0; i < pre.size(); i++)
    {
        adj[pre[i][0]].push_back(pre[i][1]);
    }
    bool ans=true;
   vector<int> visited(number,0);
        for(int i=0;i<number;++i)
            if(visited[i]==0)
                if(isCyclic(adj,visited,i)) {cout<<"Cycle is present"<<endl; return 0;};

       cout<<"Cycle is not present"<<endl;
            
    
    

    return 0;
}