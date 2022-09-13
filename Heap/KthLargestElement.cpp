#include<bits/stdc++.h>
using namespace std;

class KthLargest{

    private:
    int k;
    priority_queue<int,vector<int>,greater<int>>pq;
    public:
    KthLargest(int k,vector<int>&num)
    {
        this->k=k;
        for (int i = 0; i < num.size(); i++) pq.push(num[i]);
        while (pq.size()>this->k)pq.pop();
    }

    int add(int val)
    {
        pq.push(val);
    if(pq.size()>k)pq.pop();
    return pq.top();

}

};

int main()
{
    vector<int>nums={4, 5, 8, 2};
    int k=3;
    KthLargest* obj = new KthLargest(k, nums);

    cout<<obj->add(50)<<endl;
    cout<<obj->add(500)<<endl;
     cout<<obj->add(500)<<endl;
    
}