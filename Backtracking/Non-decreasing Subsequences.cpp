#include<bits/stdc++.h>
using namespace std;

  void  solve(int i,vector<int>&nums,set<vector<int>>&st,vector<int>&vr)
{
	
	
	if(i==nums.size()) {
        if(vr.size()>=2)
	{
		st.insert(vr);
	}
    return ;
    }
	if(!vr.size()||nums[i]>=vr.back())
	{
		
		vr.push_back(nums[i]);
		solve(i+1,nums,st,vr);
		vr.pop_back();
	}
	

	solve(i+1,nums,st,vr);
	
}

int main()
{
	vector<int>nums={-4,6,-7,7};
	set<vector<int>>st;
	vector<int>vr;
	solve(0,nums,st,vr);
	
	for(auto x:st)
	{
		for(auto y:x) cout<<y<<" ";
		cout<<endl;
	}
	
		
		
	return 0;
}