#include<bits/stdc++.h>
using namespace std;
int solve (vector<int>&vr)
{
    int mx=0;

    vector<int>temp(60,0);
    for (int i = 0; i < vr.size(); i++)
    {
        if(vr[i]%60==0)
        {
            mx+=temp[0];
        }
        else mx+=temp[60-(vr[i]%60)];

        temp[vr[i]%60]++;
    }
    
    
    return mx;
}
int main()
{
    vector<int>vr={60,60,60};
    cout<<solve(vr)<<endl;
    return 0;
}