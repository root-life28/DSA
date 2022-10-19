#include<bits/stdc++.h>
using namespace std;


int main()
{
    vector<int>nums1={2,1,3};
    vector<int>nums2={10,2,5,0};
    int n1=nums1.size(),n2=nums2.size(),ans=0;
    //x^x=0
    //x^x^x=x
    // ex: a={a,b},b={c,d,e}
    //{a^c,a^d,a^e}^{b^c,b^d,b^e}
    // {a^c^a^d^a^e^b^c^b^d^b^e}
    //{a^a^a^b^b^b^c^c^d^d^e^e}
    // {a^b}
    if(n2%2!=0)
    {
        for (int i = 0; i < n1; i++)
        {
            ans^=nums1[i];
        }
        
    }

    if(n1%2!=0)
    {
        for (int i = 0; i <nums2.size(); i++)
        {
            ans^=nums2[i];
        }
        
    }
   

    cout<<ans<<endl;
    
    

    return 0;
}