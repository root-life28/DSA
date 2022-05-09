#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> solve(vector<vector<int>>&vr)
{
      vector<vector<int>>res;
     sort(vr.begin(),vr.end());
    auto temp=vr[0];
    for (int i = 0; i <vr.size(); i++)
    {
        if(vr[i][0]<=temp[1])
        {
            temp[1]=max(temp[1],vr[i][1]);
        }
        else 
        {
            res.push_back(temp);
            temp=vr[i];
        }
    }
    
    res.push_back(temp);
    return res;
}

int main()
{
    vector<vector<int>>vr={{1,4},{2,3}};
   
    vector<vector<int>>res=solve(vr);

    for(auto x:res)
    {
        for(auto y:x)cout<<"["<<y<<"]";

        cout<<",";
    }
}