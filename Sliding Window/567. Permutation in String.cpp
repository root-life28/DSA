#include <bits/stdc++.h>
using namespace std;
bool solve(string a, string b)
{
    if (b.length() < a.length())
        return false;

    unordered_map<char, int> mp, mpb;
    for (int i = 0; i < a.size(); i++)
        mp[a[i]]++;

    for (int i = 0; i < a.length() - 1; i++)
        mpb[b[i]]++;
    int i = 0, j = a.length() - 1;
    bool y = false;

    while (j < b.length())
    {
        y = false;
        mpb[b[j]]++;
        for (auto x : mp)
        {
            char m = x.first;
            int n = x.second;
            if (mpb[m] != n)
            {
                y = true;
                break;
            }
        }
        if (y == false)
            return true;
        mpb[b[i]]--;

        if (mpb[b[i]] <= 0)
            mpb.erase(b[i]);
        i++;
        j++;
    }

    return false;
}

int main()
{
    string a = "ab";
    string b = "eidbaooo";

    cout << solve(a, b) << endl;
    return 0;
}