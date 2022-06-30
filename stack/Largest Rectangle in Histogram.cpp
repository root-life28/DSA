#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &vr)
{
    // stack<pair<int, int>> st;
    // st.push({0, vr[0]});
    // int mx = vr[0], index = 0;
    // for (int i = 1; i < vr.size(); i++)
    // {
    //     index = i;
    //     if (!st.empty())
    //     {
    //         while (!st.empty() && st.top().second >= vr[i])
    //         {
    //             index = st.top().first;
    //             int x = st.top().second;
    //             mx = max(mx, (i - index) * x);
    //             st.pop();
    //         }
    //     }
    //     st.push({index, vr[i]});
    // }

    // while (!st.empty())
    // {
    //     int x = st.top().second;
    //     index = st.top().first;
    //     mx = max(mx, ((int)vr.size() - index) * x);
    //     st.pop();
    // }

    // another way

    int mx = vr[0];

    stack<int> st;
    for (int i = 0; i < vr.size(); i++)
    {
        while (!st.empty() && vr[i] <= vr[st.top()])
        {
            int h = vr[st.top()];
            st.pop();
            int w = i - (st.empty() ? 0 : st.top() + 1);
            mx = max(mx, h * w);
        }
        st.push(i);
    }

    while (!st.empty())
    {
        int h = vr[st.top()];
        st.pop();
        int w = vr.size() - (st.empty() ? 0 : st.top() + 1);
        mx = max(mx, h * w);
    }

    return mx;
}

int main()
{
    vector<int> vr = {3, 2, 1, 5};
    cout << solve(vr) << endl;
    return 0;
}