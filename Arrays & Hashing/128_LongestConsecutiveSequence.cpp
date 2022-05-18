#include<bits/stdc++.h>
using namespace std;

//Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

//You must write an algorithm that runs in O(n) time.


int solve(vector<int>&vr)
{
    int mx=0;
       unordered_set<int>st(vr.begin(),vr.end());
        for (int i = 0; i <vr.size(); i++)
        {
            int count=0;
            if(st.find(vr[i]-1)==st.end())
            {
                
                while (st.find(vr[i]+count)!=st.end())
                {
                    st.erase(vr[i]+count);
                    count++;
                }
                
            }

            mx=max(count,mx);
        }
        
        // another way 
        // unordered_map<int,bool>mp;

        // for(auto x:vr)mp[x]=true;

        // for (int i = 0; i <vr.size(); i++)
        // {
        //     int start =vr[i]-1;
        //     int count =1;

        //     while (mp[start])
        //     {
        //         mp[start]=false;
        //         start--;
        //         count++;
        //     }
        //     start=vr[i]+1;
        //     while (mp[start])
        //     {
        //         mp[start]=false;
        //         start++;
        //         count++;
        //     }
            
        //     mp[vr[i]]=false;

        //     mx=max(count,mx);
            
        // }
        

    return mx;

}

int main()
{

   vector<int> vr={100,4,200,1,3,2};
  //vector<int> vr{0,3,7,2,5,8,4,6,0,1};
  //vector<int> vr{0,1,3,2,4,8,7,6,5,1};

    cout<<solve(vr);

    return 0;
}