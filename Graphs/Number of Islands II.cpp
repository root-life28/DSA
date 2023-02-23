#include<bits/stdc++.h>
using namespace std;

int find(int x,vector<int>&parent)
{
    if(parent[x]==x) return x;

    return parent[x]=find(parent[x],parent);
}

void Is_union(int x,int y,vector<int>&parent,vector<int>&ranks)
{
    int n=find(x,parent);
    int m=find(y,parent);
    if(n!=m)
    {
        if(ranks[n]>ranks[m])
        {
            ranks[n]+=ranks[m];
            parent[m]=n;
        }
        else 
        {
            ranks[m]+=ranks[n];
            parent[n]=m;
        }

    }


}

bool isOk(int x,int y,int m,int n)
{
    if(x>=0&&x<m&&y>=0&&y<n)return true;
    return false;
}
int main()
{
    int m=8;
    int n=4;
    vector<vector<int>>positions={{0,0},{0,1},{1,2},{1,2}};
    vector<int>parent(m*n+1);
    for(int i=0;i<m*n+1;i++)parent[i]=i;
    vector<int>ranks(m*n+1,1);

    vector<vector<int>>grid(m,vector<int>(n,0));

    int cnt=0;

    vector<int>ans;

    for (int i = 0; i <positions.size(); i++)
    {
        
        int x=positions[i][0];
        int y=positions[i][1];
      if(grid[x][y]){
        ans.push_back(cnt);
      }
      else {
        int p=x*n+y;

        grid[x][y]=1;
        cnt++;


        if(isOk(x+1,y,m,n)&&grid[x+1][y])
        {
            int a=find(p,parent);
            int b=find((x+1)*n+y,parent);

            if(a!=b)
            {
                cnt-=1;
                Is_union(a,b,parent,ranks);
            }
            
        }

         if(isOk(x,y+1,m,n)&&grid[x][y+1])
        {
            int a=find(p,parent);
            int b=find(x*n+y+1,parent);

            if(a!=b)
            {
                cnt-=1;
                Is_union(a,b,parent,ranks);
            }
            
        }

         if(isOk(x-1,y,m,n)&&grid[x-1][y])
        {
            int a=find(p,parent);
            int b=find(((x-1)*n)+y,parent);

            if(a!=b)
            {
                cnt-=1;
                Is_union(a,b,parent,ranks);
            }
           
        }
         if(isOk(x,y-1,m,n)&&grid[x][y-1])
        {
            int a=find(p,parent);
            int b=find(x*n+y-1,parent);

            if(a!=b)
            {
                cnt-=1;
                Is_union(a,b,parent,ranks);
            }
            
        }

        ans.push_back(cnt);

        
    }
    }
    for(auto x:ans)cout<<x<<" ";


}