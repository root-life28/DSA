#include <bits/stdc++.h>
using namespace std;

bool can(vector<vector<char>> &vr, int i, int j, char k)
{

    for (int c = 0; c < 9; c++)
        if (vr[i][c] == k)
            return false;
    for (int r = 0; r < 9; r++)
        if (vr[r][j] == k)
            return false;

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (vr[i / 3 * 3 + x][j / 3 * 3 + y] == k)
                return false;
        }
    }

    return true;
}

bool solve(vector<vector<char>> &vr, int i, int j)
{
    if (i == 8 && j == 9)
        return true;
    if (j == 9)
    {
        i = i + 1;
        j = 0;
    }
    if (vr[i][j] != '.')
        return solve(vr, i, j + 1);
    else
    {
        for (int k = 1; k <= 9; k++)
        {
            string s = to_string(k);
            if (can(vr, i, j, s[0]))
            {
                vr[i][j] = s[0];
                if (solve(vr, i, j + 1))
                    return true;
            }
        }

        vr[i][j] = '.';
    }
    return false;
}

int main()
{
    vector<vector<char>> vr = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}

    };

    cout << solve(vr, 0, 0)
         << endl;

    for (auto x : vr)
    {
        for (auto y : x)
            cout << y << ' ';

        cout << endl;
    }

    return 0;
}