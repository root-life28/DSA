#include<bits/stdc++.h>
using namespace std;
unordered_map<char,string>mp;
string temp="";

void latter(string x,int index,vector<string>&vr)
{
    if(index==x.length()) return;

    string xm=mp[x[index]];
    for (int i = 0; i < xm.length(); i++)
    {
       if(index<x.length()){
        temp+=xm[i];
        latter(x,index+1,vr);
        if(temp.length()==x.length())vr.push_back(temp);
        temp.pop_back();}
    }
    
}

int main()
{
    string s="23";
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
    vector<string>vr;
    latter(s,0,vr);
    for(auto x:vr)cout<<x<<endl;
}