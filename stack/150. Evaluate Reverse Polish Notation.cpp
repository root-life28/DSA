#include <bits/stdc++.h>
using namespace std;
int solve(vector<string> &vr)
{
    stack<int> st;
    for (int i = 0; i < vr.size(); i++)
    {
        if (vr[i] == "+" || vr[i] == "-" || vr[i] == "/" || vr[i] == "*")
        {

            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            if (vr[i] == "+")
            {
                st.push((a + b));
            }
            else if (vr[i] == "*")
            {
                st.push((a * b));
            }
            else if (vr[i] == "/")
            {
                st.push((a / b));
            }
            else if (vr[i] == "-")
            {
                st.push((a - b));
            }
        }
        else
        {
            int val = stoi(vr[i]);
            st.push(val);
        }
    }

    return st.top();
}
int main()
{
    vector<string> vr = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << solve(vr) << endl;
    return 0;
}