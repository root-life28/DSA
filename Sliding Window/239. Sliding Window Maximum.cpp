#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &vr, int k)
{
    int j = 0;
    vector<int> res;
    deque<int> dq;

    for (int i = 0; i < vr.size(); i++)
    {
        while (!dq.empty() && dq.back() < vr[i])
        {
            dq.pop_back();
        }
        dq.push_back(vr[i]);

        if (i - j == k - 1)
        {
            res.push_back(dq.front());
            if (dq.front() == vr[j])
                dq.pop_front();
            j++;
        }
    }

    return res;

    // multiset<int> st;
    // vector<int> res;
    // for (int i = 0; i < vr.size(); i++)
    // {
    //     st.insert(vr[i]);
    //     if (i >= k - 1)
    //     {
    //         res.push_back(*st.rbegin());
    //         st.erase(st.find(vr[i - k + 1]));
    //     }
    // }

    // return res;
}

int main()
{
    vector<int> vr = {-1, 1};
    vector<int> res = solve(vr, 1);

    for (auto x : res)
        cout << x << " ";
    return 0;
}