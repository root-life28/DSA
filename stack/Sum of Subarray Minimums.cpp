#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>nums={3,1,2,4};
    stack<int>st;
    int mod=pow(10,9)+7;
    long long int ans=0;
    for (int i = 0; i <=nums.size(); i++)
    {
        while (!st.empty()&&(i==nums.size() or nums[st.top()]>=nums[i]))
        {
            int p=st.top();
            st.pop();
            int left=st.empty()?-1:st.top();
            int right=i;
           long long int cnt=((p-left)*(right-p))%mod;

           cout<<cnt<<" "<<p<<endl;
           ans=(ans+(cnt*nums[p]))%mod;
               
        }
        
        st.push(i);
    }

    cout<<ans<<endl;
    
    return 0;
}