#include<bits/stdc++.h>
using namespace std;

//Design an algorithm to encode a list of strings to a string. 
//The encoded string is then sent over the network and is decoded back to the original list of strings.
string encode(vector<string>&vr)
{
    string s="";
    for (int i = 0; i < vr.size(); i++)
    {
       s+=to_string(vr[i].size())+":"+vr[i];
        
    }
    return s;
}

vector<string> solve(vector<string>&vr)
{
    string s=encode(vr);

    vector<string> res;
    int n=0;
    
    for (int i = 0; i <s.length(); i++)
    {
        if(s[i]==':')
        {
            string x="";
            for (int j = i+1; j <=i+n; j++)x+=s[j];
           res.push_back(x);
           
            i+=n;
             n=0;
            
        }
        else
        {
            n=(n*10)+(s[i]-'0');
        }
    }
    
    

  return res;


}

int main()
{
    //vector<string>vr={"lint","code","love","you"};
    vector<string>vr={"we", "say", ":;", "yes"};

    vector<string> res=solve(vr);

    for (int i = 0; i <res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    
   

    return 0;
}