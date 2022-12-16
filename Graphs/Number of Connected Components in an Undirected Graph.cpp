#include<bits/stdc++.h>
using namespace std;

 void solve(vector<vector<int>>&node, vector<bool> &vis, int n) {
        if(vis[n]) return;
        vis[n] = 1;
        
        for (int i = 0; i < node[n].size(); i++) {
            
                solve(node, vis, node[n][i]);
            
        }
    }

int main()
{
    vector<vector<int>>edges={{0,1},{0,2},{1,2}};
    int n=5;
  if (n == 0) return 0;
      
        int cnt = 0;
        vector<bool> vis(n, false);
        vector<vector<int>> node(n);
    
        for (int i = 0; i < edges.size(); i++) {
            node[edges[i][0]].push_back(edges[i][1]);
            node[edges[i][1]].push_back(edges[i][0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                cnt++;
                solve(node, vis, i);
            }
        }
       
        cout<<cnt;
    
    
    
    return 0;
}