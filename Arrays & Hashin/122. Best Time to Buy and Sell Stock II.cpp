#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>&vr)
{

        int buy=INT_MAX;
        int sell =0;

        for (int i = 0; i <vr.size(); i++)
        {
            if(vr[i]<buy)
            {
                buy=vr[i];
            }
            else
            {
                sell=max(sell,sell+vr[i]-buy);
                buy=vr[i];
            }
        }
        

        return sell;

    
}

int main()
{
    vector<int>vr={7,1,5,8,3,2,9};
    cout<<solve(vr);
}