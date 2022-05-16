#include<bits/stdc++.h>
using namespace std;

int neighbors(int i,int j,int r,int c,vector<vector<int>>&vr)
{
  bool a,b,cc,d,e,f,g,h;
  

    a=i>0&&j>0&&vr[i-1][j-1]&&vr[i-1][j-1]!=3;
    b=i>0&&vr[i-1][j]&&vr[i-1][j]!=3;

    cc=i>0&&j+1<c&&vr[i-1][j+1]&&vr[i-1][j+1]!=3;

    d=j>0&&vr[i][j-1]&&vr[i][j-1]!=3;
    e=j+1<c&&vr[i][j+1]&&vr[i][j+1]!=3;

    f=i+1<r&&j>0&&vr[i+1][j-1]&&vr[i+1][j-1]!=3;
    g=i+1<r&&j+1<c&&vr[i+1][j+1]&&vr[i+1][j+1]!=3;

    h=i+1<r&&vr[i+1][j]&&vr[i+1][j]!=3;

    //cout<<a<<b<<cc<<d<<e<<f<<g<<h<<endl;

    return (a+b+cc+d+e+f+g+h);

}

void solve(vector<vector<int>>&vr)
{
    int r=vr.size();
    int c=vr[0].size();

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(vr[i][j]==1)
            {
              int k=neighbors(i,j,r,c,vr);
              if(k<2)
              {
                  vr[i][j]=2;
              }
              else if(k==2||k==3)continue;
              else vr[i][j]=2;


            }
            else {
                int k=neighbors(i,j,r,c,vr);
                if(k==3)
                {
                    vr[i][j]=3;
                }
            }
        }
        
    }

    for (int i = 0; i <r; i++)
    {
        for (int j = 0; j <c; j++)
        {
            if(vr[i][j]==2)vr[i][j]=0;
            else if(vr[i][j]==3)vr[i][j]=1;
        }
        
    }
    
    
}

int main()
{
    vector<vector<int>>vr={{0,1,0},{0,0,1},{1,1,1},{0,0,0}};

       // cout<<neighbors(0,1,vr.size(),vr[0].size(),vr);
    solve(vr);

    for (int i = 0; i <vr.size(); i++)
    {
        for (int j = 0; j <vr[0].size(); j++)
        {
            cout<<vr[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
    return 0;
}