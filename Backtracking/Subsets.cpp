#include<bits/stdc++.h>
using namespace std;
vector<int>sub_set;
void subset(vector<int>&vr,int index,int n,vector<vector<int>>&res)
{
    if(n==index)
    {
        res.push_back(sub_set);
    }

    else{
        sub_set.push_back(vr[index]);
        subset(vr,index+1,n,res);
        sub_set.pop_back();
        subset(vr,index+1,n,res);
    }
   
}

int main()
{
    vector<int>vr={1,2,3};
    vector<vector<int>>res;
    subset(vr,0,vr.size(),res);

    //sort(res.begin(),res.end());

    for(auto x:res)
    {
        for(auto y:x)cout<<y;
        cout<<endl;
    }

    
    return 0;
}