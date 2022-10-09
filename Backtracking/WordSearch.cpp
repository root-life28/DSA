#include<bits/stdc++.h>
using namespace std;
bool vis[7][7]={0};
  bool a,b,c,d={0};
  

bool check(vector<vector<char>>&vr,string s,int i,int j,int index)
{
   if(index==s.size()) return true;

    if(i+1<vr.size()&&index<s.size()&&vr[i+1][j]==s[index]&&vis[i+1][j]==0)
        {
            
           vis[i+1][j]=1;
           a= check(vr,s,i+1,j,index+1);  
           vis[i+1][j]=0;                   
        }
   if(j+1<vr[0].size()&&index<s.size()&&vr[i][j+1]==s[index]&&vis[i][j+1]==0)
        {          
            vis[i][j+1]=1;
            b=check(vr,s,i,j+1,index+1);
            vis[i][j+1]=0;                     
        }

    if(i-1>=0&&index<s.size()&&vr[i-1][j]==s[index]&&vis[i-1][j]==0)
        {         
           vis[i-1][j]=1;
            c= check(vr,s,i-1,j,index+1);
            vis[i-1][j]=0;                   
        }
    if(j-1>=0&&index<s.size()&&vr[i][j-1]==s[index]&&vis[i][j-1]==0)
        {         
            vis[i][j-1]=1;
           d= check(vr,s,i,j-1,index+1);
           vis[i][j-1]=0;           
        }

    return a or b or c or d;
}

int main()
{
    vector<vector<char>>vr={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string s="DFCC";
    bool ans=false;
    for (int i = 0; i < vr.size(); i++)
    {
        for (int j = 0; j < vr[0].size(); j++)
        {
            if(vr[i][j]==s[0])
            { 
                vis[i][j]=1;
                ans=check(vr,s,i,j,1);
                if(ans){
                    cout<<"ok"<<endl;
                    cout<<i<<" "<<j<<endl;
                    break;
                }
                else {
                   memset(vis,0,sizeof(vis));
                    a=b=c=d={0};
                }

            }
        }
        
    }
    

    return 0;
}