#include <bits/stdc++.h>
using namespace std;

int solve(string s, int k)
{
    int mx = 1;
    int fq = 0;
    int i = 0, j = 0;
    unordered_map<char, int> mp;
    while (j < s.length())
    {
        mp[s[j]]++;
        fq = max(fq, mp[s[j]]);

        int w = j - i + 1;
        if (w - fq <= k)
        {
            mx = max(mx, w);
        }
        else
        {
            mp[s[i]]--;
            i++;
        }

        j++;
    }

    return mx;
}
int main()
{

    cout << solve("ABAB", 2);
    return 0;
}