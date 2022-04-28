#include<bits/stdc++.h>
using namespace std;

vector <int> solve(vector<int>&vr,int k)
{
   vector<int> res;

   unordered_map<int,int>mp;
   for (int i = 0; i < vr.size(); i++)
   {
       mp[vr[i]]++;
   }
   vector<pair<int,int>>temp;
   for (auto x:mp)
   {    
       temp.push_back({x.second,x.first});
   }
    sort(temp.begin(),temp.end(),[](const pair<int,int> &x, const pair<int,int> &y){
        return x.first>y.first;
    });

    if(k>temp.size()) return res;

    for (int i = 0; i <k; i++)
    {
        res.push_back(temp[i].second);
    }
    
    
   
return res;
    


    
}

int main()
{
    vector<int>vr={1,1,1,2,2,3};

    vector <int>res=solve(vr,1);

    for(auto x:res)cout<<x<<" ";
    
    return 0;
}