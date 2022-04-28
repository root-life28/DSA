#include<bits/stdc++.h>
using namespace std;

vector <int> solve(vector<int>&vr)
{
    vector<int>res(vr.size(),vr.back());

    for(int i=vr.size()-2;i>=1;i--)
    {
        res[i]=res[i+1]*vr[i];
    }
    int temp=1;
    for (int i = 0; i < vr.size()-1; i++)
    {
        res[i]=temp*res[i+1];
        temp*=vr[i];
    }

    res[vr.size()-1]=temp;
    


return res;
    
}

int main()
{
    vector<int>vr={-1,1,0,-3,3};

    vector <int>res=solve(vr);

    for(auto x:res)cout<<x<<" ";
    
    return 0;
}