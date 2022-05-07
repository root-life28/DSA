#include<bits/stdc++.h>
using namespace std;


void solve(vector<int>& vr1, int m, vector<int>& vr2, int n)
{
    int i=m-1;
    int j=n-1;
    int k=n+m-1;

    while (i>=0&&j>=0)
    {
        if(vr1[i]>vr2[j])
        {
            vr1[k--]=vr1[i--];
        }
        else 
        {
            vr1[k--]=vr2[j--];
        }
    }

    while (i>=0)vr1[k--]=vr1[i--];
    while (j>=0)vr1[k--]=vr2[j--];
  
    
}

int main()
{
    vector<int> vr1={4,0,0,0,0,0};

    vector<int> vr2={1,2,3,5,6};
    int m=1,n=5;
    solve(vr1,m,vr2,n);
    for (int i = 0; i <vr1.size(); i++)
    {
        cout<<vr1[i]<<" ";
    }
    


    return 0;
}