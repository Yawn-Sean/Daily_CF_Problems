#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> xs(n), ys(n);
    for (int i = 0; i < n; i ++) cin >> xs[i] >> ys[i];

    set<array<int, 3>> lines;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < i; j ++) {
            int dx = xs[i] - xs[j], dy = ys[i] - ys[j];
            int g = __gcd(dx, dy);
            dx /= g, dy /= g;
            if (dx < 0 || (dx == 0 && dy < 0))
                dx = -dx, dy = -dy;
            array<int, 3> ar = {dx, dy, xs[i] * dy - ys[i] * dx};
            lines.emplace(ar);
        }
    }

    int k = lines.size();
    long long ans = 1ll * k * (k - 1) / 2;
    map<pair<int, int>, int> mp;

    for (auto &v: lines)
        ans -= mp[{v[0], v[1]}] ++;

    cout << ans;
    return 0;
}