#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &vr, int target)
{
    sort(vr.begin(), vr.end());

    long long int mx = INT_MAX, mi = INT_MIN;
    for (int i = 0; i < vr.size(); i++)
    {
        int l = i + 1, r = vr.size() - 1;
        while (l < r)
        {
            long long int sum = vr[i] + vr[l] + vr[r];

            if (sum < target)
            {
                mi = max(mi, sum);
                l++;
            }
            else if (sum > target)
            {
                mx = min(mx, sum);
                r--;
            }
            else
                return sum;
        }
    }

    return target - mi < mx - target ? mi : mx;
}

int main()
{
    vector<int> vr = {-1, 2, -1, -4};
    int target = 2;
    cout << solve(vr, target);

    return 0;
}