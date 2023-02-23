#include<bits/stdc++.h>
using namespace std;
  int dfs(const vector<vector<int>>& graph, int u, int prev, int seats,
          long long& ans) {
    int people = 1;
    for (const int v : graph[u]) {
      if (v == prev)
        continue;
      people += dfs(graph, v, u, seats, ans);
    }
    if (u != 0)
  
      ans += ceil((double)people / seats);
    return people;
  }
int main()
{
    vector<vector<int>>nodes={{3,1},{3,2},{1,0},{0,4},{0,5},{4,6}};
    int n=nodes.size();
    int seat=2;
     long long ans = 0;
    vector<vector<int>> graph(nodes.size() + 1);

    for (const vector<int>& road : nodes) {
      graph[road[0]].push_back(road[1]);
      graph[road[1]].push_back(road[0]);
    }

    dfs(graph, 0, -1, seat, ans);

    cout<<ans;
    

    
    return 0;
}