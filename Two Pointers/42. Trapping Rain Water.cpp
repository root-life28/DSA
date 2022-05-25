#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &vr)
{
    int mx = 0;

    int i = 0, r = vr.size() - 1;
    int leftMax = vr[0], rightMax = vr[r];

    while (i < r)
    {
        int temp = min(leftMax, rightMax);
        if (vr[i] <= temp)
        {
            mx += max(0, temp - vr[i]);
            i++;
        }
        else
        {

            mx += max(0, temp - vr[r]);
            r--;
        }

        leftMax = max(leftMax, vr[i]);
        rightMax = max(rightMax, vr[r]);
    }

    return mx;
}

int main()
{
    vector<int> vr = {4, 2, 0, 3, 2, 5};
    cout << solve(vr) << endl;
    return 0;
}