#include<bits/stdc++.h>
using namespace std;


void solve(vector<int>&vr)
{
    int f,s;

    for (f=vr.size()-2; f>=0; f--)if(vr[f]<vr[f+1])break;
    if(f<0)reverse(vr.begin(),vr.end());
    else {
         for (s=vr.size()-1; s>f; s--)if(vr[s]>vr[f])break;
         swap(vr[f],vr[s]);
         reverse(vr.begin()+f+1,vr.end());
    }
    

}

int main()
{
    vector<int>vr={3,2,1};
    solve(vr);
    for (int i = 0; i <vr.size(); i++)
    {
        cout<<vr[i]<<" ";
    }

    return 0;
    
}