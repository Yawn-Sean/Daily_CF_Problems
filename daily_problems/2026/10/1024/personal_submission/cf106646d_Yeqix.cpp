#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

using ld = long double;
constexpr ld inf = 1e12;

int sgn(int x) {
    return (x > 0) - (x < 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, h;
    cin >> n >> h;
    vector<vector<array<int, 2>>> f(n);
    vector<int> ml, mr;
    vector<vector<ld>> L, R;
    ld res = 0;
    for (auto& a : f) {
        int k;
        cin >> k;
        a.resize(k);
        int mn = 1e9, mx = -1e9;
        for (auto& [x, y] : a) {
            cin >> x >> y;
            mn = min(mn, x), mx = max(mx, x);
        }
        ml.push_back(mn), mr.push_back(mx);
        vector<ld> l(h + 1, inf), r(h + 1, -inf);
        for (int i = 0; i < k; i++) {
            int nxt = (i + 1) % k;
            auto [x, y] = a[i];
            auto [cx, cy] = a[nxt];
            if (y == cy) {
                l[y] = min<ld>(l[y], min(x, cx)), r[y] = max<ld>(r[y], max(x, cx));
            } else {
                ld s1 = (ld)(cx - x) / (cy - y);
                int s2 = sgn(cy - y);
                ld st = x;
                while (y != cy) {
                    l[y] = min(l[y], st), r[y] = max(r[y], st);
                    st += s1 * s2, y += s2;
                }
                l[y] = min(l[y], st), r[y] = max(r[y], st);
            }
        }
        L.push_back(l), R.push_back(r);
        res += mx - mn;
    }

    auto get = [&](int i, int j) -> ld {
        if (i == j) {
            return 0;
        }
        int lst = mr[i] - ml[j];
        ld ans = inf;
        for (const auto& [x, y] : f[i]) {
            ld l = R[i][y], r = L[j][y] + lst;
            ans = min(ans, r - l);
        }
        for (const auto& [x, y] : f[j]) {
            ld l = R[i][y], r = L[j][y] + lst;
            ans = min(ans, r - l);
        }
        return ans;
    };

    vector<vector<ld>> pre(n, vector<ld>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pre[i][j] = get(i, j);
        }
    }

    vector<vector<ld>> dp(n, vector<ld>(1 << n));
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) {
                for (int k = 0; k < n; k++) {
                    if (mask >> k & 1) {
                        continue;
                    }
                    int nxt = mask | (1 << k);
                    dp[k][nxt] = max(dp[k][nxt], dp[i][mask] + pre[i][k]);
                }
            }
        }
    }

    ld ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i].back());
    }

    cout << fixed << setprecision(12) << res - ans;
    return 0;
}