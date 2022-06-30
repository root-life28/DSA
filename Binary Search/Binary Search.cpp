#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &vr, int target)
{
    int l = 0, r = vr.size() - 1, mid;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (vr[mid] == target)
            return mid;
        else
        {
            if (vr[mid] < target)
            {
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> vr = {-1, 0, 3, 5, 9, 12};
    int target = 12;
    cout << solve(vr, target);
    return 0;
}