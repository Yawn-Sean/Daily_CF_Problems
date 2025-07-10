#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pts(m);
    for (auto &[x, y]: pts) cin >> x >> y;

    map<tuple<int, int, long long>, int> mp;

    for (int i = 0; i < m; i ++) {
        auto [x1, y1] = pts[i];
        for (int j = 0; j < i; j ++) {
            auto [x2, y2] = pts[j];
            int dx = x2 - x1, dy = y2 - y1;
            int g = gcd(dx, dy);
            dx /= g, dy /= g;

            if (dx < 0 || (dx == 0 && dy < 0))
                dx = -dx, dy = -dy;

            mp[{dx, dy, 1ll * x1 * dy - 1ll * dx * y1}] ++;
        }
    }

    vector<int> ans(n + 1, 0);

    for (auto &[k, v]: mp) {
        auto [dx, dy, val] = k;
        if (dy && val % dy == 0 && val / dy >= 1 && val / dy <= n) {
            ans[val / dy] = max(ans[val / dy], v);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i ++)
        res += sqrt(ans[i] * 2) + 1;

    cout << res;

    return 0;
}
