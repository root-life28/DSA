#include<bits/stdc++.h>
using namespace std;

//Given an integer array nums, return true if any value appears at least twice in the array, 
//and return false if every element is distinct.

bool solve(vector<int>& vr)
{
    unordered_map<int,int>mp;
    for (size_t i = 0; i < vr.size(); i++)
    {
        if(mp[vr[i]])
        {
            return true;
        }
        mp[vr[i]]++;
    
    }
    return false;
}

int main()
{
    
    int n;
    cin>>n;
    vector<int>vr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>vr[i];
    }
    
   
   cout<<solve(vr);

    return 0;
}