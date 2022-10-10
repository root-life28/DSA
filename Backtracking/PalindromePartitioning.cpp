#include<bits/stdc++.h>
using namespace std;
vector<string>vr;

bool palindrome(int start,int end,string s)
{
    while (start<=end)
    {
        if(s[start++]!=s[end--]) return false;
    }
    
    return true;
}
void pl(string s,int index,vector<vector<string>>&res)
{
    if(index==s.length())
    {
       res.push_back(vr);
        return;
    }
    for (int i = index; i < s.length(); i++)
    {
        if(palindrome(index,i,s))
        {
            vr.push_back(s.substr(index,i-index+1));
            pl(s,i+1,res);
            vr.pop_back();
        }
    }
    
}
int main()
{
    string s="xxbebx";
    vector<vector<string>>res;

    pl(s,0,res);

    for(auto x:res){
        for(auto y:x) cout<<y<<" ";
        cout<<endl;
    }

    return 0;
}