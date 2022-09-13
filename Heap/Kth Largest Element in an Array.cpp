#include<bits/stdc++.h>
using namespace std;
 int findKthLargest(vector<int>&nums,int k)
 {
    int size=nums.size();
    priority_queue<int,vector<int>,greater<int>>pq;

    for (int i = 0; i < size; i++)
    {
        if(pq.size()==k)
        {
            int x=pq.top();
            if(x<nums[i])
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        else
        {
            pq.push(nums[i]);
        }
    }


    return pq.top();
    
 }

int main()
{
    vector<int>nums={3,2,3,1,2,4,5,5,6};
    int k=6;

    cout<<findKthLargest(nums,k)<<endl;
    return 0;
}