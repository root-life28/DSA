#include<bits/stdc++.h>
using namespace std;

vector<int>x;


void cSum(vector<int>&vr,int index,int target,int sum,vector<vector<int>>&res)
{
   
     if(sum==target){ 

      // for(auto m:x)cout<<m;
      // cout<<endl; 

      res.push_back(x);
      
      return;}

   
      for (int i = index; i <vr.size(); i++)
      {
        if(i>index&&vr[i]==vr[i-1])continue;
        if(sum+vr[i]<target){
          x.push_back(vr[i]);
          sum+=vr[i];
          cSum(vr,i+1,target,sum,res);
          x.pop_back();
          sum-=vr[i];
        }
      }
      
    

}

int main()
{
    vector<int>vr={10,1,2,7,6,1,5};
    sort(vr.begin(),vr.end());
    vector<vector<int>>res;
    cSum(vr,0,8,0,res);

    return 0;
}