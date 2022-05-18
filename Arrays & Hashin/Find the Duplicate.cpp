#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&vr)
{  //using bitset
    // int num;
    // const int n=vr.size();

    // bitset<100002>bit;

    // for (int i = 0; i < n; i++)
    // {
    //     if(bit[vr[i]]==1)
    //     {
    //         num= vr[i];
    //         break;
    //     }
    //     else bit[vr[i]]=1;
    // }

    // using binary search

    int low=1,high=vr.size()-1;

    while (low<=high)
    {
        int mid =low+(high-low)/2;
        int cnt=0;
        for (int i = 0; i <vr.size(); i++)
        {
            if(vr[i]<=mid)cnt++;
        }

        if(cnt<=mid)low=mid+1;
        else high=mid-1;
        
    }
    

    
    return low;
}

int main()
{
    vector<int>vr={3,1,3,4,2};
    cout<<solve(vr);
    return 0;
}