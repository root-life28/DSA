#include<bits/stdc++.h>

using namespace std;

int solve(vector<int>&vr)
{
    int mxArea=0;
    int l=0,r=vr.size()-1;

    while (l<r)
    {
     
        mxArea=max(min(vr[l],vr[r])*(r-l),mxArea);

        if(vr[l]<=vr[r])
        {
            l++;
        }
        else r--;
    }
    

    return mxArea;
}

int main()
{
     vector<int>vr={1,8,6,2,5,4,8,3,7};
     cout<<solve(vr)<<endl;

    return 0;
}