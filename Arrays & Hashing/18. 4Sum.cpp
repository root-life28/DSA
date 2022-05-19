#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<int> &vr, int target)
{
    sort(vr.begin(), vr.end());
    vector<vector<int>> res;
    int n = vr.size();
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long int temp = vr[i] + vr[j];
            int l = j + 1, r = n - 1;

            while (l < r)
            {
                sum = vr[l] + vr[r];
                sum += temp;

                if (sum < target)
                {
                    l++;
                }

                else if (sum > target)
                {
                    r--;
                }
                else
                {

                    res.push_back(vector<int>{vr[i], vr[j], vr[l], vr[r]});
                    while (l + 1 < r && vr[l] == vr[l + 1])
                        l++;
                    while (l < r - 1 && vr[r] == vr[r - 1])
                        r--;

                    l++, r--;
                }
            }

            while (j + 1 < n && vr[j] == vr[j + 1])
                j++;
        }

        while (i + 1 < n && vr[i] == vr[i + 1])
            i++;
    }

    return res;
}

int main()
{
    // vector<int> vr = {1000000000, 1000000000, 1000000000, 1000000000};
    vector<int> vr = {2, 2, 2, 2, 2, 2};
    int target = 8;

    vector<vector<int>> res = solve(vr, target);

    for (auto x : res)
    {
        for (auto y : x)
            cout << y << " ";

        cout << endl;
    }

    return 0;
}