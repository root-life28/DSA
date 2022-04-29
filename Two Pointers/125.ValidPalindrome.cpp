#include<bits/stdc++.h>
using namespace std;


bool solve(string s)
{
    string x="";
   for (int i = 0; i <s.length(); i++)if(isalnum(s[i])) x+=tolower(s[i]);

       int i=0,j=x.length()-1;
       while (i<=j)
       {
           if(x[i]==x[j])
           {
               i++,j--;
           }
           else return false;
       }
       
   
    return true;
    
}

int main()
{
    string s="A man, a plan, a canal: Panama";
    
    //string s="0p";

    if(solve(s))
    {
        cout<<"true";
    }
    else cout<<"false";

    return 0;
}