#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int x[n], y[m];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> y[i];
    }
    vector<int> cx(n), cy(m);
    ll res = 0;

    vector<pair<int, int>> vx, vy;

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;

        bool fx = binary_search(x, x + n, a);
        bool fy = binary_search(y, y + m, b);

        if (fx && fy) {
            continue;
        }
        if (fx) {
            int u = lower_bound(y, y + m, b) - y - 1;
            cy[u]++;
            vx.emplace_back(a, u);
        } else {
            int u = lower_bound(x, x + n, a) - x - 1;
            cx[u]++;
            vy.emplace_back(b, u);
        }
    }
    for (int i = 0; i < n; i++) {
        res += 1LL * cx[i] * (cx[i] - 1) / 2;
    }
    for (int i = 0; i < m; i++) {
        res += 1LL * cy[i] * (cy[i] - 1) / 2;
    }
    for (auto p : {vx, vy}) {
        sort(p.begin(), p.end());
        for (int l = 0, r; l < p.size(); l = r) {
            r = l;
            while (r < p.size() && p[l] == p[r]) {
                r++;
            }
            res -= 1LL * (r - l) * (r - l - 1) / 2;
        }
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
