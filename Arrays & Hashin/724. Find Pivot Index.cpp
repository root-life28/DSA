#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>&vr)
{
    int index=-1;

    for (int i = 1; i <vr.size(); i++)vr[i]+=vr[i-1];
   
   if(vr[0]==vr[vr.size()-1]) return 0;
   for (int i = 1; i <vr.size(); i++)
   {
       if(vr[vr.size()-1]-vr[i]==vr[i-1]) 
       {
           index =i;
           break;
       }
   }
   
    return index;

}

int main()
{
  vector<int> vr={2,1,-1} ;
  cout<<solve(vr);
}