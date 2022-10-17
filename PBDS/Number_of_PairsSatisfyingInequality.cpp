#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> 
    ordered_set; 


int main()
{   vector<int>nums1={-4,-4,4,-1,-2,5};
    vector<int>nums2={-2,2,-1,4,4,3};
    int diff=1;
    long long int ans=0;
    ordered_set ost;
    for (int i = 0; i <nums1.size(); i++)
    {
        int m=nums1[i]-nums2[i];

        ans+=ost.order_of_key({m+diff,INT_MAX});
        ost.insert({m,i});
    }

    cout<<ans<<endl;
    


    return 0;
}