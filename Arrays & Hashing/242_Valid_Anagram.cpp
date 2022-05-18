#include<bits/stdc++.h>
using namespace std;

//Given two strings s and t, return true if t is an anagram of s, and false otherwise.

bool solve(string a,string b)
{
    if(b.length()!=a.length())return false;
    unordered_map<char,int> mp;
    for (int i = 0; i <a.length(); i++)
    {
        mp[a[i]]++;
        mp[b[i]]--;
    }

    for (int i = 0; i <26; i++)
    {
      if(mp[i+'a']!=0) return false;
    }
    
    
    return true;
}

int main()
{

   string a,b;
   cin>>a>>b;
   cout<<solve(a,b);

    return 0;
}