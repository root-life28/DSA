#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=3;
      int a = 0, b = 1, c = 1, c2, mod = 1e9 + 7;
        while (--n) {
            c2 = (c * 2 % mod + a) % mod;
            a = b;
            b = c;
            c = c2; 

        }

        cout<<c;
    return 0;
}