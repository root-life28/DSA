#include<bits/stdc++.h>
using namespace std;

 bool isCyclic(vector<vector<int>>& adj,vector<int>& visited,int curr,vector<int>&temp)
    {
        if(visited[curr]==2)
            return true;
        
        visited[curr] = 2;
        for(int i=0;i<adj[curr].size();++i)
            if(visited[adj[curr][i]]!=1)
                if(isCyclic(adj,visited,adj[curr][i],temp))
                    return true;
        
        visited[curr] = 1;
        temp.push_back(curr);
        return false;
    }

int main()
{
    vector<vector<int>>prerequisites={{1,0},{2,0},{3,1},{1,2}};
    int numCourses=4;

    vector<vector<int>>adj(numCourses);
    vector<int>visit(numCourses,0);
    vector<int>temp;

    for (int i = 0; i < numCourses; i++)
    adj[prerequisites[i][0]].push_back(prerequisites[i][1]);


 
        for(int i=0;i<numCourses;++i)
            if(visit[i]==0)
                if(isCyclic(adj,visit,i,temp))
                {
                   temp={};
                    break; // return temp;
                }

    for (int i = 0; i <temp.size(); i++)
    {
        cout<<temp[i]<<" ";
    }
    
    
    
    return 0;// return temp;
}