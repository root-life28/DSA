#include<bits/stdc++.h>
using namespace std;

bool solve(string &s)
{
   
   int a=0,b=0;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='(')a++;
        else a--;

        if(s[i]!=')')b++;
        else b--;

        if(b<0) return false;
        a=max(a,0);
       
    }
    
return a==0;

}

int main()
{
    string s="()(";
    cout<<solve(s);
    return 0;
}