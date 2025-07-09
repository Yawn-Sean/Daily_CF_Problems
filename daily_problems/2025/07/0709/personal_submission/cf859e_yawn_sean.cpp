#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/dsu.hpp"

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

    int n;
    cin >> n;

    int mod = 1e9 + 7;

    vector<pair<int, int>> edges(n);
    for (auto &[u, v]: edges)
        cin >> u >> v, u --, v --;
    
    atcoder::dsu uf(2 * n);

    for (auto &[u, v]: edges) uf.merge(u, v);

    vector<int> cnt(2 * n, 0);
    vector<bool> flg(2 * n, 1);

    for (auto &[u, v]: edges) {
        cnt[uf.leader(u)] ++;
        if (u == v) flg[uf.leader(u)] = 0;
    }

    int ans = 1;

    for (int i = 0; i < 2 * n; i ++) {
        if (uf.leader(i) == i && flg[i]) {
            int sz = uf.size(i);
            if (cnt[i] < sz) ans = 1ll * ans * sz % mod;
            else ans = 1ll * ans * 2 % mod;
        }
    }

    cout << ans;

    return 0;
}