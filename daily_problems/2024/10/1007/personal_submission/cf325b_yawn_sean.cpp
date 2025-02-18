#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;

    bool flg = false;

    for (int i = 0; i < 60; i ++) {
        long long v = 1ll << i, l = 0, r = min(1ll << 31, n / max(v - 1, 1ll));
        while (l <= r) {
            long long m = (l + r) / 2;
            if (m * (m - 1) / 2 + m * (v - 1) <= n) l = m + 1;
            else r = m - 1;
        }
        if (r * (r - 1) / 2 + r * (v - 1) == n && r & 1) {
            cout << r * v << '\n';
            flg = true;
        }
    }

    if (!flg) cout << -1;

    return 0;
}