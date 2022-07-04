#include <bits/stdc++.h>
using namespace std;
int pos(vector<int> &vr)
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

    return mid;
}
int solve(vector<int> &vr, int target)
{
    int index = -1;
    int l = 0, r = vr.size() - 1, mid;

    int x = pos(vr);

    if (target >= vr[x] && target <= vr[r])
    {
        l = x;
    }
    else
        r = x;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (vr[mid] == target)
            return mid;
        else if (vr[mid] < target)
        {
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    return index;
}

int main()
{
    vector<int> vr = {100, 200, 1, 2, 50, 60, 70};
    int target = 12;
    cout << solve(vr, target);
    return 0;
}