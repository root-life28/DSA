#include<bits/stdc++.h>
using namespace std;

//Given an array of strings strs, group the anagrams together. You can return the answer in any order.

string countSort(string s)
{
    int count[26]={0};
    for(char a:s)
    {
        count[a-'a']++;
    }
     string x;
     for (int i = 0; i <26; i++)
     {
         x+=string(count[i],i+'a');
     }

     return x;
     
}

vector<vector<string>> solve(vector<string>&vr)
{

    unordered_map<string,vector<string>>mp;
    int j=1;

    for (int i = 0; i <vr.size(); i++)
    {
        string x=vr[i];
        sort(x.begin(),x.end());
         mp[x].push_back(vr[i]);

        // using countingSort since all char are lowercase
       // mp[countSort(x)].push_back(vr[i]);
           
           
    }
    vector<vector<string>>res;
    for (auto x:mp )
    {
        res.push_back(x.second);
    }
    return res;
}

int main()
{

    vector<string> vr={"eat","tea","tan","ate","nat","bat"};

   vector<vector<string>> res;

   res=solve(vr);
  
   for (auto x:res)
   {
     for(auto i:x)cout<<i<<" ";
     cout<<endl;
   }
   

    return 0;
}