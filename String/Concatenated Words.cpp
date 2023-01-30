#include<bits/stdc++.h>
using namespace std;


bool solve(int j,string &s,unordered_map<string,int>&mp,int last)
{
   
    if(j==s.length()){return last>1;}
    string x="";
    bool a=false;
    for (int k = j; k <s.size(); k++)
        {
            x+=s[k];
            if(mp[x])
            { a=solve(k+1,s,mp,last+1);
              
            }
        }
    return a;
}


int main()
{
    vector<string>words={"cats","b","a","cat","catsdogcats","dog","dogcatsdog","ab","rat","ratcatdogcat"};

    unordered_map<string,int>mp;
    for (auto x:words)
    {
        mp[x]=1;
    }
    vector<string>ans;
   

 
   for (int i = 0; i < words.size(); i++)
   {   
        if(solve(0,words[i],mp,0))
        {
            ans.push_back(words[i]);
            cout<<words[i]<<" ";
        }
   }
   
    
    

    return 0;
}