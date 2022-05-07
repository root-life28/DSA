#include<bits/stdc++.h>
using namespace std;


void solve(vector<int>& vr)
{
   int num=0;

   for (int i = 0; i <vr.size(); i++)
   {
       if(vr[i]!=0)swap(vr[num++],vr[i]);;
   }

}

int main()
{
    vector<int> vr={0,0,0,3};
    solve(vr);
    for (int i = 0; i <vr.size(); i++)
    {
        cout<<vr[i]<<" ";
    }
    


    return 0;
}