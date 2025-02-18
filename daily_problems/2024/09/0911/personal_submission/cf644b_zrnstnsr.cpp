#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, b;
    cin >> n >> b;
    queue<pair<int, int>> q;
    vector<ll> ans(n);
    ll tl = 0;
    for (int i = 0; i < n; ++i) {
        int t, d;
        cin >> t >> d;
        while (!q.empty() && tl <= t) {
            auto [j, d] = q.front(); q.pop();
            ans[j] = tl += d;
        }
        if (tl <= t) ans[i] = tl = t + d;
        else if (q.size() < b) q.push({i, d});
        else ans[i] = -1;
    }
    while (!q.empty()) {
        auto [j, d] = q.front(); q.pop();
        ans[j] = tl += d;
    }
    for (auto v: ans) print("{} ", v);
    println();
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
