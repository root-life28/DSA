#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s="ababcbacadefegdehijhklij";
    unordered_map<char,int>mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]=i;
    }

    int Last=0,size=0;
    vector<int>ans;
    for (int i = 0; i <s.length(); i++)
    {
        size++;
        Last=max(mp[s[i]],Last);
        if(Last==i)
        {
            ans.push_back(size);
            size=0;
        }
     
    }

    for(auto x:ans)cout<<x<<" "<<endl;
    
    
    return 0;
}