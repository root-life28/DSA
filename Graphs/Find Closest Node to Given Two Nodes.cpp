#include<bits/stdc++.h>
using namespace std;
  void dfs(int node, vector<int>& edges, vector<int>& distance, vector<bool>& visited){
        visited[node] = true;
        int neighbor = edges[node];
        if (neighbor != -1 && visited[neighbor] == false) {
            distance[neighbor] = distance[node] + 1;
            dfs(neighbor, edges, distance, visited);
        }
    }


int main()
{
    vector<int>edges={1,2,-1};
    int node1=0,node2=2;

  
       int n = edges.size();
        int ans = -1;
        int minDist = INT_MAX;
        
        vector<int> dist1(n, 0), dist2(n, 0);
        vector<bool> visited1(n, false), visited2(n, false);
          dfs(node1, edges, dist1, visited1);
        dfs(node2, edges, dist2, visited2);

   for(int currNode = 0; currNode < n; currNode++){
            if(visited1[currNode] == true && visited2[currNode] == true && minDist > max(dist1[currNode], dist2[currNode])){
                minDist = max(dist1[currNode], dist2[currNode]);
                ans = currNode;
            }
        }
       

   cout<<ans;
  
    return 0;
}