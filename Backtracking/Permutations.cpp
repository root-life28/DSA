#include<bits/stdc++.h>
using namespace std;

void per(vector<int>&vr,int n,int i)
{
    if(n==i)
    {
        for (int i = 0; i <vr.size(); i++)
        {
            cout<<vr[i];
        }

        cout<<endl;
        return ;
        
    }

    for (int j =i; j < n; j++)
    {
        swap(vr[i],vr[j]);
        per(vr,n,i+1);
        swap(vr[i],vr[j]);
    }
    

}
int main()
{
    vector<int>vr={1,2,3};
    int n=vr.size();
    per(vr,n,0);
    return 0;
}