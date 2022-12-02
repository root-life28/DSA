#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>gas={5,1,2,3,4};
    vector<int>cost={4,4,1,5,1};
    int t=0,c=0;
    int p=0;
    for (int i = 0; i <gas.size(); i++)
    {
        t+=gas[i]-cost[i];
        c+=gas[i]-cost[i];
        if(c<0){p=i+1;c=0;}
    }
    

    cout<< (t >= 0 ? p : -1);
  
    
    
    return 0;
}