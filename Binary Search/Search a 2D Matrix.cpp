#include <bits/stdc++.h>
using namespace std;

bool solve(vector<vector<int>> &vr, int target)
{

    int row = 0, col = vr[0].size() - 1;

    while (row < vr.size() && col >= 0)
    {
        if (vr[row][col] == target)
            return true;
        else
        {
            if (vr[row][col] < target)
                row++;
            else
                col--;
        }
    }

    // int col = vr[0].size();
    // int row = vr.size();
    // int l = 0, r = col * row - 1, m;
    // while (l <= r)
    // {
    //     m = (l + r) / 2;
    //     int x = (m / col);
    //     int y = m % col;
    //     if (vr[x][y] == target)
    //     {
    //         cout << x << " " << y << endl;
    //         return true;
    //     }
    //     else
    //     {
    //         if (vr[x][y] < target)
    //         {
    //             l = m + 1;
    //         }
    //         else
    //             r = m - 1;
    //     }
    // }

    return false;
}

int main()
{
    vector<vector<int>> vr =
        {{1, 3, 5, 7},
         {10, 11, 16, 20},
         {23, 30, 34, 60}};

    int target = 20;

    cout << solve(vr, target);

    return 0;
}