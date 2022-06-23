#include <bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &vr)
{
    vector<int> res(vr.size(), 0);
    stack<int> st;
    st.push(0);

    for (int i = 1; i < vr.size(); i++)
    {

        while (!st.empty() && vr[st.top()] < vr[i])
        {
            res[st.top()] = i - st.top();
            st.pop();
        }

        st.push(i);
    }

    return res;
}
int main()
{
    vector<int> vr = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = solve(vr);

    for (auto x : res)
        cout << x;

    return 0;
}