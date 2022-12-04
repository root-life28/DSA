#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>>triplets={{2,5,3},{1,8,4},{1,7,5}};
    vector<int>target={2,7,5};
    int a=0,b=0,c=0;
    for (int i = 0; i < triplets.size(); i++)
    {
    if(triplets[i][0]<=target[0]&&
    triplets[i][1]<=target[1]&&
    triplets[i][2]<=target[2])
       {
        a=max(a,triplets[i][0]);
        b=max(b,triplets[i][1]);
        c=max(c,triplets[i][2]);
       }

       

    }

   if(target[0]!=a||target[1]!=b||target[2]!=c)  return false;  
   else return 1;

   
   return 0;
}