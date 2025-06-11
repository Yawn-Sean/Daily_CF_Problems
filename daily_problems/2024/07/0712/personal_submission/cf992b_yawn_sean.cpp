#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l, r, x, y;
    cin >> l >> r >> x >> y;
    if (y % x) {
        cout << 0;
        return 0;
    }
    y /= x;
    int ans = 0;
    for (int i = 1; i * i <= y; i ++) {
        if (y % i == 0 && __gcd(i, y / i) == 1 && i * x >= l && i * x <= r && y / i * x >= l && y / i * x <= r) {
            ans ++;
            if (i != y / i) ans ++;
        }
    }
    cout << ans;

    return 0;
}