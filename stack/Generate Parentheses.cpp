#include <bits/stdc++.h>
using namespace std;
void req(int start, int end, int n, vector<string> &res, string &s)
{
    if (s.size() == n * 2)
    {
        res.push_back(s);
        return;
    }

    if (start < n)
    {
        s.push_back('(');
        req(start + 1, end, n, res, s);
        s.pop_back();
    }
    if (end < start)
    {
        s.push_back(')');
        req(start, end + 1, n, res, s);
        s.pop_back();
    }
}
vector<string> solve(int k)
{
    vector<string> res;
    string s;
    req(0, 0, k, res, s);

    return res;
}
int main()
{
    int n = 3;
    vector<string> res = solve(n);

    for (auto x : res)
        cout << x << endl;
    return 0;
}