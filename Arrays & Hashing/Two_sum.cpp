#include<bits/stdc++.h>
using namespace std;

//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

vector<int> solve(vector<int>&vr,int target)
{
        map<int,int>mp;
        vector<int> res;
        for (int i = 0; i <vr.size(); i++)mp[vr[i]]=i+1;
        for (int i = 0; i <vr.size(); i++)
        {
            if(mp[target-vr[i]]!=0&&mp[target-vr[i]]-1!=i)
            {
                res.push_back(i);
                res.push_back(mp[target-vr[i]]-1);
                break;
            }
        }
        return res;

}

int main()
{

   vector<int> vr={2,7,11,15};

   vector<int> res;
   res=solve(vr,13);
   for (int i = 0; i < res.size(); i++)
   {
       cout<<res[i]<<" ";
   }
   

    return 0;
}