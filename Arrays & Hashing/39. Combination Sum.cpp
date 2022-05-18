#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &res, vector<int> &vr, vector<int> &cur, int total, int i, int target)
{
    if (total == target)
    {
        res.push_back(cur);
        return;
    }

    if (i >= vr.size() || total > target)
        return;
    cur.push_back(vr[i]);
    DFS(res, vr, cur, total + vr[i], i, target);
    cur.pop_back();
    DFS(res, vr, cur, total, i + 1, target);
}

vector<vector<int>> solve(vector<int> &vr, int target)
{
    vector<vector<int>> res;
    vector<int> cur;
    DFS(res, vr, cur, 0, 0, target);
    return res;
}

int main()
{
    vector<int> vr = {2, 3, 5};
    vector<vector<int>> res = solve(vr, 8);

    for (auto x : res)
    {
        for (auto y : x)
            cout << y << " ";

        cout << endl;
    }
    return 0;
}