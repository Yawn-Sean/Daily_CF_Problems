#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k, x, y;
    cin >> n >> m >> k;
    vector<int> xs(n+1), ys(m+1);
    xs[n] = ys[m] = 1e7;
    vector<pair<int, int>> ponx, pony;
    for (int i = 0; i < n; i++) cin >> xs[i];
    for (int i = 0; i < m; i++) cin >> ys[i];
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        int px = *lower_bound(xs.begin(), xs.end(), x);
        int py = *lower_bound(ys.begin(), ys.end(), y);
        if (x == px && y == py) continue;
        if (x == px) ponx.push_back({y, x});
        if (y == py) pony.push_back({x, y});
    }
    sort(ponx.begin(), ponx.end());
    sort(pony.begin(), pony.end());
    long long ans = 0;
    int pxn = ponx.size(), pyn = pony.size();
    for (int i = 0, j = 0, t = 0; t <= m; t++, i = j) {
        unordered_map<int, int> mp;
        while (j < pxn && ponx[j].first < ys[t]) {
            mp[ponx[j].second]++, j++;
        }
        ans += 1LL * (j - i) * (j - i - 1) / 2;
        for (auto& [k, v] : mp) ans -= 1LL * v * (v - 1) / 2;
    }

    for (int i = 0, j = 0, t = 0; t <= n; t++, i = j) {
        unordered_map<int, int> mp;
        while (j < pyn && pony[j].first < xs[t]) {
            mp[pony[j].second]++, j++;
        }
        ans += 1LL * (j - i) * (j - i - 1) / 2;
        for (auto& [k, v] : mp) ans -= 1LL * v * (v - 1) / 2;
    }

    cout << ans << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
