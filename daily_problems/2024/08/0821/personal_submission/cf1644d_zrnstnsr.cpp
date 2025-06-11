#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

int R[200010], C[200010];

ll Pow(int e, int n) {
    if (!n) return 1;
    ll res = Pow(e, n / 2);
    res *= res; res %= mod;
    if (n % 2) res *= e, res %= mod;
    return res;
}

void solve() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<pair<int, int>> op(q);
    while (q--) cin >> op[q].first >> op[q].second;
    q = 0;
    for (auto [r, c]: op) {
        if (R[r] && C[c]) continue;
        n -= R[r] ^ 1;
        m -= C[c] ^ 1;
        R[r] = C[c] = 1;
        ++q;
        if (!n || !m) break;
    }
    for (auto [r, c]: op) R[r] = C[c] = 0;
    cout << Pow(k, q) << '\n';
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    // T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
