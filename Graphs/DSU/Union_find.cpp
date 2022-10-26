#include<bits/stdc++.h>
using namespace std;
class Graph
{


public:
    int V;
  list<pair<int,int>>l;
    Graph(int V)
    {
        this->V=V;
    }

    void addEdge(int u,int v)
    {
        l.push_back({u,v});
    }
    
    int findSet(int i,vector<int>&parent)
    {
        if(parent[i]==-1) return i;

        return parent[i]=findSet(parent[i],parent);
    }

    bool union_set(int x,int y,vector<int>&parent)
    {
        int s1=findSet(x,parent);
        int s2=findSet(y,parent);

        if(s1!=s2)
        {
            parent[s1]=s2;
            return true;
        }

        return false;
    }
};




int main()
{
    Graph st(4);

    st.addEdge(1,2);
    st.addEdge(2,3);
    st.addEdge(3,4);
    st.addEdge(4,5);
    vector<int>parent(5);
    for (int i = 0; i < 5; i++)
    {
       parent[i]=-1;
    }
    
    for (auto x:st.l)
    {
        if(st.union_set(x.first,x.second,parent))continue;
        else cout<<x.first<<" "<<x.second<<endl;
    }
    
    
    return 0;
}