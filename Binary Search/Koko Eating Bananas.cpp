#include <bits/stdc++.h>
using namespace std;

int check(int num, vector<int> &vr)
{

    int total = 0;
    for (int i = 0; i < vr.size(); i++)
    {
        total += vr[i] / num;
        if (vr[i] % num)
            total++;
    }

    return total;
}

int solve(vector<int> &vr, int h)
{
    long long int sum = *max_element(vr.begin(), vr.end());

    long long int l = 1, r = sum, mid;
    int x;
    long long int m = INT_MAX;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (mid == 0)
            mid = 1;
        x = check(mid, vr);
        // cout << x;
        if (x <= h)
        {
            m = min(mid, m);
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    return m;
}
int main()
{
    vector<int> piles = {312884470};
    int h = 968709470;
    cout << solve(piles, h) << endl;
    return 0;
}