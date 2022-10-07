#include<bits/stdc++.h>
using namespace std;
vector<int>x;
set<vector<int>>st;


// space opt
void subSet(vector<int>&vr,int index,vector<vector<int>>&res)
{
    res.push_back(x);

    for (int i = index; i <vr.size(); i++)
    {
        if(i>index&&vr[i]==vr[i-1])continue;
        x.push_back(vr[i]);
        subSet(vr,i+1,res);
        x.pop_back();
    }
    

}
void subset(vector<int>&vr,int i,int n)
{
    
    if(n==i) return;
    x.push_back(vr[i]);
   st.insert(x);
    subset(vr,i+1,n);
    x.pop_back();
    subset(vr,i+1,n);


}

int main()
{
    vector<int>vr={1,2,2};
    vector<vector<int>>res;
    sort(vr.begin(),vr.end());

    subSet(vr,0,res);

    for(auto m:res){
        for(auto y:m)cout<<y;
        cout<<endl;
    }

  

    return 0;
}