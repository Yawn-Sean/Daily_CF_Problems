#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    int cnt[16384] = {0};
    int u; cin >> u; ++cnt[u];

    auto gosper = [](int n, int k, vector<int> &res) {
        if (!k) { res.push_back(0); return; }
        int s = (1 << k) - 1, m = 1 << n;
        while (s < m) {
            res.push_back(s);
            int lb = s & -s;
            int r = s + lb;
            s = ((s ^ r) >> __builtin_ctz(lb) + 2) | r;
        }
    };
    vector<int> _xor;
    gosper(14, k, _xor);

    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        cin >> u;
        for (auto v: _xor) {
            ans += cnt[u ^ v];
        }
        ++cnt[u];
    }
    println("{}", ans);
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
