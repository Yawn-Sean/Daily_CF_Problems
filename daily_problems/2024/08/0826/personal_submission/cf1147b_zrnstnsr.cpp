#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> edge;
    while (m--) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        edge.insert({--u, --v});
    }
    auto check = [&](int p) -> bool {
        for (auto [u, v]: edge) {
            u = (u + p) % n;
            v = (v + p) % n;
            if (u > v) swap(u, v);
            if (!edge.count({u, v})) return false;
        }
        return true;
    };
    bool suc = check(1);
    for (int p = 2; p * p <= n && !suc; ++p) {
        if (n % p == 0) suc = check(p) || check(n / p);
    }
    println("{}", suc ? "Yes" : "No");
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
