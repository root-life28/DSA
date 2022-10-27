#include<bits/stdc++.h>
using namespace std;


int findSet(int x,vector<int>&parent)
{
    if(parent[x]==x) return x;

    return parent[x]=findSet(parent[x],parent);
}

void unionSet(int x,int y,vector<int>&parent)
{
    x=findSet(x,parent);
    y=findSet(y,parent);
    if(x!=y){
    parent[x]=max(parent[x],parent[y]);
    parent[y]=max(parent[x],parent[y]);
    }
}

int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    int l,r,c;
    vector<int>parent(n+2);
    for(int i=1;i<=n+1;i++)parent[i]=i;
  
    struct COLORFUL_ARRAY
    {
        int a;
        int b;
        int c;
    };
    
    vector<COLORFUL_ARRAY>vr;
    
   for (int i = 0; i <q; i++)
   {
        cin>>l>>r>>c;
        vr.push_back({l,r,c});
        
    }

    vector<int>ans(n+2);
// using Dsu
    for (int i = q-1; i>=0; i--)
    {
        
      int index=findSet(vr[i].a,parent);

        while (index<=vr[i].b)
        {
            ans[index]=vr[i].c;
            unionSet(index,index+1,parent);
            index=findSet(index,parent);
        }
        
      

    }
    

//other way

//    for (ll i = 0; i <n; i++)
//    {
//         for (ll j =q-1; j>=0; j--)
//         {
//             if(i+1>=vr[j].a&&i+1<=vr[j].b)
//             {
//                 parent[i+1]=vr[j].c;
//                 break;
//             }
//         }
        
//    }
   
    for (int i =1; i <=n; i++)
    {
        cout<<ans[i]<<endl;
    }
    

    
    
    return 0;
}