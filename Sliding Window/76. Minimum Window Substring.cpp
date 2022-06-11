#include <bits/stdc++.h>
using namespace std;
string solve(string a, string b)
{
    string res = "";
    unordered_map<char, int> mpb, mpa;
    for (auto x : b)
        mpb[x]++;

    int x = b.length();

    int i = 0, j = 0;
    int have = 0;
    int mi = INT_MAX;
    int m = -1, n = -1;

    while (i <= j && j <= a.length())
    {
        if (have == x)
        {
            if (j - i < mi)
            {
                mi = j - i;
                n = i, m = j;
            }
            if (mpb[a[i]] != 0)
            {
                if (mpa[a[i]] <= mpb[a[i]])
                {
                    mpa[a[i]]--;
                    have--;
                }
                else
                    mpa[a[i]]--;
            }

            i++;
        }
        else if (have < x && mpb[a[j]] != 0)
        {
            if (mpa[a[j]] < mpb[a[j]])
            {
                mpa[a[j]]++;
                have++;
            }
            else
                mpa[a[j]]++;
            j++;
        }
        else
            j++;
    }

    for (int i = n; i < m; i++)
        res += a[i];

    return res;
}
int main()
{
    string a, b;
    a = "A";
    b = "AA";

    cout << solve(a, b) << endl;
    return 0;
}