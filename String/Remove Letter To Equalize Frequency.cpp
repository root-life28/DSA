#include<bits/stdc++.h>
using namespace std;

bool solve(string s)
{
    
    vector<int>vr(26);
    for (int i = 0; i < s.size(); i++)
    {
        vr[s[i]-'a']++;
    }

    sort(vr.begin(),vr.end());
    int one=0;
    int p=-1;
    int total=0;
    for (int i = 0; i < vr.size(); i++)
    {
        if(vr[i]==1)one++;
        

        if(vr[i])
        {   total++;
            if(p==-1)p=i;
        }
    }
    if(total==1) return true;
    if(one>1)
    {
        if(vr.back()-vr[p]==0||vr.back()-vr[p]==1&&vr[vr.size()-1]!=vr[vr.size()-2]) return true;
        else return false;

    }
    else if(one==1)
    {
        if(vr.back()-vr[p]==1||vr.back()-vr[p+1]==0) return true;
        else return false;
    }
    else
    {
        if(vr.back()-vr[p]==1&&vr[vr.size()-1]!=vr[vr.size()-2]) return true;
        else return false;
    }


    

}

int main()
{
    string word="aaaabbbbccc";
    if(solve(word))cout<<"Ok";
    else cout<<"NO";
    return 0;
}