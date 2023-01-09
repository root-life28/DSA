#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>>points={{0,0},{2,2},{-1,-1}};
         int n = points.size();
         int result = 2;
        if (n >= 1) {
    
            for (int i = 0; i < n; i++) {
                unordered_map<double, int> cnt;
                for (int j = 0; j < n; j++) {
                    if (j != i) {
                        cnt[atan2(points[j][1] - points[i][1], points[j][0] - points[i][0])]++;
                    }
                }
                for (auto x : cnt) {
                    result = max(result, x.second + 1);
                }
            }
        }
        else result=1;

        cout<<result;

    return 0;
}