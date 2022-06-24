#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &position, vector<int> &speed, int target)
{
    stack<double> st;
    vector<pair<int, int>> vr(position.size());
    for (int i = 0; i < position.size(); i++)
    {
        vr[i] = {position[i], speed[i]};
    }

    sort(vr.begin(), vr.end(), greater<pair<int, int>>());

    for (int i = 0; i < vr.size(); i++)
    {
        double x = 1.0 * (target - vr[i].first) / vr[i].second;
        if (st.empty())
        {
            st.push(x);
        }
        else
        {
            if (st.top() >= x)
            {
                continue;
            }
            else
                st.push(x);
        }
    }

    return st.size();
}
int main()
{
    vector<int> position = {8, 12, 16, 11, 7};
    vector<int> speed = {6, 9, 10, 9, 7};
    int target = 17;
    cout << solve(position, speed, target);
    return 0;
}
