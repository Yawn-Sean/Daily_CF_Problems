#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/dsu"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edges(m);

    for (auto &[u, v, c]: edges) {
        char x;
        cin >> u >> v >> x;
        u --, v --;
        c = (x == 'S' ? 1 : 0);
    }

    if (n % 2 == 0) return cout << -1, 0;

    int target = n / 2;
    vector<int> ans;

    atcoder::dsu uf_base(n), real_uf(n);

    for (int i = 0; i < m; i ++) {
        auto [u, v, c] = edges[i];
        if (c == 0) uf_base.merge(u, v);
    }

    for (int i = 0; i < m; i ++) {
        auto [u, v, c] = edges[i];
        if (c && uf_base.merge(u, v)) {
            real_uf.merge(u, v);
            ans.emplace_back(i);
        }
    }

    for (int i = 0; i < m; i ++) {
        auto [u, v, c] = edges[i];
        if (ans.size() < target && c && real_uf.merge(u, v)) {
            ans.emplace_back(i);
        }
    }

    if (ans.size() != target) return cout << -1, 0;

    for (int i = 0; i < m; i ++) {
        auto [u, v, c] = edges[i];
        if (c == 0 && real_uf.merge(u, v)) {
            ans.emplace_back(i);
        }
    }

    if (ans.size() == n - 1) {
        cout << ans.size() << '\n';
        for (auto &x: ans) cout << x + 1 << ' ';
    }
    else cout << -1;

    return 0;
}