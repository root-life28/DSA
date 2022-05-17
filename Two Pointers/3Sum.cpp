#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> solve(vector<int>&vr)
{
    sort(vr.begin(),vr.end());
    vector<vector<int>>res;
    for (int i = 0; i <vr.size(); i++)
    {
        int l=i+1,r=vr.size()-1;

        while (l<r)
        {
            int sum=vr[i]+vr[l]+vr[r];

            if(sum<0)l++;
            else if(sum>0)r--;
            else 
            {
                vector<int>temp={vr[i],vr[l],vr[r]};
                //cout<<vr[i]<<" "<<vr[l]<<" "<<vr[r]<<endl;
                res.push_back(temp);

                while(l+1<r&&vr[l]==vr[l+1])l++; // to avoid duplicate of vr[l] number
                while(l<r-1&&vr[r]==vr[r-1])r--; // // to avoid duplicate of vr[r] number

                l++,r--; // normal increase -decrease
            }
        }

        while (i+1<vr.size()&&vr[i]==vr[i+1])i++; //to avoid duplicate of vr[i] number
       
    }

    return res;

}

int main()
{
    vector<int>vr={-1,0,1,2,-1,-4};
     vector<vector<int>>res=solve(vr);

     for(auto x:res){
     for(auto y:x)cout<<y<<" ";
     cout<<endl;
     }
    return 0;
}