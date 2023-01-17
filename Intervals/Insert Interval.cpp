#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>>intervals={{1,3},{6,9},{11,12}};
    vector<int> newInterval={2,5};
    vector<vector<int>>ans;
  int i=0;
  int n=intervals.size();

        while (i < n && intervals[i][1] < newInterval[0]) ans.push_back(intervals[i++]);
        while (i < n && intervals[i][0] <= newInterval[1]) newInterval = {min(intervals[i][0], newInterval[0]), max(intervals[i][1], newInterval[1])}, i++;
        ans.push_back(newInterval);
        while (i < n) ans.push_back(intervals[i++]);
  

  
  
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<endl;
    }
    

    
    return 0;
}