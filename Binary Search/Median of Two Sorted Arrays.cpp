#include <bits/stdc++.h>
using namespace std;

double solve(vector<int> &v1, vector<int> &v2)
{
    if (v1.size() > v2.size())
        swap(v1, v2);

    int x = v1.size();
    int y = v2.size();
    int total = x + y;

    if (x == 0 || y == 0)
    {
        if (x == 0)
        {
            if (total % 2 == 1)
            {
                return v2[total / 2];
            }
            else
                return 1.0 * (v2[total / 2] + v2[total / 2 - 1]) / 2;
        }
        else
        {
            if (total % 2 == 1)
            {
                return v1[total / 2];
            }
            else
                return 1.0 * (v1[total / 2] + v1[total / 2 - 1]) / 2;
        }
    }

    int low = 0, high = x;
    while (low <= high)
    {
        int partX = (low + high) / 2;
        int partY = (total + 1) / 2 - partX;

        int leftX = partX == 0 ? INT_MIN : v1[partX - 1];
        int rightX = partX == x ? INT_MAX : v1[partX];

        int leftY = partY == 0 ? INT_MIN : v2[partY - 1];
        int rightY = partY == y ? INT_MAX : v2[partY];
        if (leftX <= rightY && leftY <= rightX)
        {
            if ((x + y) % 2 == 0)
            {
                return 1.0 * (max(leftX, leftY) + min(rightX, rightY)) / 2;
            }
            else
                return 1.0 * (max(leftX, leftY));
        }
        else if (leftX > rightY)
        {
            high = partX - 1;
        }
        else
            low = partX + 1;
    }
    return 0.0;
}

int main()
{
    vector<int> v1 = {};
    vector<int> v2 = {2, 4};
    cout << solve(v1, v2);
    return 0;
}