#include<bits/stdc++.h>
using namespace std;


vector<int> solve(vector<int>&vr,int target)
{
    vector<int> index(2);
    int i=0;
    int j=vr.size()-1;
    while (i<j)
    {
        if(vr[i]+vr[j]==target)
        {
            index[0]=i+1;
            index[1]=j+1;
            return index;
        }
        else if(target-vr[i]<vr[j])
        {
            j--;
        }
        else i++;
    }

    return index;
    
}

int main()
{
    vector<int> vr={1,2,3,4,5,6,7,11,15};
    vector<int> res;
    res=solve(vr,9);
    cout<<res[0]<<" "<<res[1]<<endl;

    return 0;
}