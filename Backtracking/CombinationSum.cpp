#include<bits/stdc++.h>
using namespace std;
 vector<int>vr;
 set<vector<int>>st;
void combination(vector<vector<int>> &res, vector<int> &vr, vector<int> &cur, int total, int i, int target)
{

    if (total == target)
    {
        res.push_back(cur);
        return;
    }

    if (i >= vr.size() || total > target)
        return;
    cur.push_back(vr[i]);
   
    combination(res, vr, cur, total + vr[i], i, target);
    cur.pop_back();
    combination(res, vr, cur, total, i + 1, target);
   
    
}


int main()
{
   vector<int>vr={2,3,5};
   vector<int>curr;

   vector<vector<int>>res;

   combination(res,vr,curr,0,0,8);
   cout<<res.size();

    return 0;
}