#include <bits/stdc++.h>
using namespace std;
int solve(string s)
{
    int mx = 0;
    unordered_map<char, int> mp;
    int i = 0, j = 0;
    int n = s.size();
    while (i < n && j < n)
    {
        if (mp[s[j]] != 0)
        {
            mp.erase(s[i++]);
        }
        else
            mp[s[j++]]++;
        mx = max(mx, (int)mp.size());
    }

    return mx;
}

int main()
{
    string s = "pwwkew";
    cout << solve(s) << endl;
    return 0;
}