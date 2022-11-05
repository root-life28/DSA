#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>nums={-1,0,-2};
    int n=nums.size();
    int mx=1;
    int mi=1;
    int ans=INT_MIN;
    for (int i = 0; i <n; i++)
    {
    
        int temp=mx;
        mx=max(nums[i]*mx,max(nums[i]*mi,nums[i]));

        int x=min(nums[i]*temp,nums[i]);
        mi=min(x,nums[i]*mi);

       ans=max(mx,ans);

    }

    cout<<ans;
    
}