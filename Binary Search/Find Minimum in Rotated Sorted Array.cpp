#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &vr)
{
    int l = 0, r = vr.size() - 1, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (vr[mid] >= vr[r] && vr[l] >= vr[r])
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }

    return vr[mid];
}
int main()
{
    vector<int> vr = {0, 4, 5, 6, 7};
    cout << solve(vr) << endl;
    return 0;
}