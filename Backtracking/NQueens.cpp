#include<bits/stdc++.h>
using namespace std;
bool isOk(int i,int j,vector<vector<char>>&vr,int n)
{
    for (int x = 0; x <n; x++)
    {
        if(vr[i][x]=='Q') return false;
        if(vr[x][j]=='Q') return false;
    }

   if(i>0&&j>0)
   {
        int m=j;
        for (int x = i; x>=0&&m>=0; x--,m--)
        {
            if(vr[x][m]=='Q') return false;
        }
   }


     if(i>0&&j<n)
   {
        int m=i;
        for (int x = j; x<n&&m>=0; x++,m--)
        {
            if(vr[m][x]=='Q') return false;
        }
   }
if(i<n&&j>0)
   {
        int m=j;
        for (int x = i; x<n&&m>=0; x++,m--)
        {
            if(vr[x][m]=='Q') return false;
        }
   }


if(i<n&&j<n)
   {
        int m=i;
        for (int x = j; x<n&&m<n; x++,m++)
        {
            if(vr[m][x]=='Q') return false;
        }
   }

    return true;
}

void solve(vector<vector<char>>&vr,int n,int index, vector<vector<string>>&r)
{
   

    if(index==n)
    {
        vector<string>vx;
        for (int i = 0; i <n; i++)
        {
            string xy="";
            for (int j = 0; j <n; j++) xy+=vr[i][j];
            vx.push_back(xy);
        }
        r.push_back(vx);

        return;  
    }
    for (int j = 0; j <n; j++)
    {
        if(isOk(index,j,vr,n))
        {
            
            vr[index][j]='Q';
            solve(vr,n,index+1,r);
            vr[index][j]='.';
        }
    }
    
}

int main()
{
    int n=4;
    vector<vector<char>>vr(n,vector<char>(n,'.'));
  

    vector<vector<string>>res;


    solve(vr,n,0,res);

    for (auto x:res)
    {
        for(auto y:x)cout<<y<<endl;
        cout<<endl;
    }

    
    return 0;
}