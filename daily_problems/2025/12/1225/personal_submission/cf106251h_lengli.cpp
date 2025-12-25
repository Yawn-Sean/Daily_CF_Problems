#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

bool sign(const pair<ll,ll>& v) {
    // v[1] > 0 or (v[1] == 0 and v[0] > 0)
    if (v.second > 0) return true;
    if (v.second == 0 && v.first > 0) return true;
    return false;
}

// 等价于 Python 的 cmp(v1, v2)
bool cmp(const pair<ll,ll>& v1, const pair<ll,ll>& v2) {
    // return -1 if v1 < v2
    // return 1 if v1 > v2
    // 排序时我们写成 v1 < v2
    __int128 val1 = (__int128)v1.second * v2.first;
    __int128 val2 = (__int128)v2.second * v1.first;
    return val1 < val2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<ll,ll>> pts_pos, pts_neg;

    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        pair<ll,ll> pt = {x, y};
        if (sign(pt)) pts_pos.push_back(pt);
        else pts_neg.push_back(pt);
    }

    sort(pts_pos.begin(), pts_pos.end(), cmp);
    sort(pts_neg.begin(), pts_neg.end(), cmp);

    vector<pair<ll,ll>> pts;
    for (auto &p : pts_pos) pts.push_back(p);
    for (auto &p : pts_neg) pts.push_back(p);

    // check(i, j)
    auto check = [&](int i, int j) -> bool {
        ll x1 = pts[i].first,  y1 = pts[i].second;
        ll x2 = pts[j].first,  y2 = pts[j].second;

        ll dx = x2 - x1;
        ll dy = y2 - y1;

        ll target = dx * dx + dy * dy;
        ll v1 = x1 * x1 + y1 * y1;
        ll v2 = x2 * x2 + y2 * y2;

        return target > v1 && target > v2;
    };

    // saved[i][j]
    vector<vector<char>> saved(n, vector<char>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            saved[i][j] = check(i, j);
        }
    }

    ll ans = n;

    for (int i = 0; i < n; i++) {
        vector<ll> dp(n, 0);
        dp[i] = 1;

        for (int x = i; x < n; x++) {
            if (dp[x] == 0) continue;
            for (int y = x + 1; y < n; y++) {
                if (saved[x][y]) {
                    dp[y] += dp[x];
                    if (dp[y] >= MOD) dp[y] -= MOD;
                }
            }
        }

        for (int x = 0; x < n; x++) {
            if (saved[i][x]) {
                ans += dp[x];
                if (ans >= MOD) ans -= MOD;
            }
        }
    }

    cout << ans % MOD << '\n';
    return 0;
}
