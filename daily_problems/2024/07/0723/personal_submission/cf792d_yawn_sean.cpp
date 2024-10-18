#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long orig;
    int q;
    cin >> orig >> q;

    while (q --) {
        long long n;
        string s;
        cin >> n >> s;

        for (auto &c: s) {
            long long x = n & -n;
            if (c == 'L') {
                if (x > 1) n -= x / 2;
            }
            else if (c == 'R') {
                if (x > 1) n += x / 2;
            }
            else {
                if (x * 2 < orig)
                    n -= x, n |= x << 1;
            }
        }
        cout << n << '\n';
    }

    return 0;
}