#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n=4;
    vector<vector<int>>flights={{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src=0;
    int dst=3;
    int k=1;

     unordered_map<int, vector<pair<int, int>>> graph;
        for(auto e: flights) graph[e[0]].push_back({e[1], e[2]});
        vector<int> prices(n, -1);
        queue<pair<int, int>> q; q.push({src, 0});
        ++k;
        while(!q.empty()&&k) {
           
         int s=q.size();
         for (int i = 0; i < s; i++)
         {
            auto x=q.front();
            q.pop();
            for (int j = 0; j <graph[x.first].size(); j++)
            {
                int price=x.second + graph[x.first][j].second;
                if(prices[graph[x.first][j].first]==-1||price<prices[graph[x.first][j].first])
                {
                    prices[graph[x.first][j].first]=price;
                    q.push({graph[x.first][j].first,price});
                }
            }
            
         }
         
            k--;
        }
        cout<< prices[dst];

    


    return 0;
}