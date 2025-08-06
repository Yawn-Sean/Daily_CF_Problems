#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/segtree.hpp"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

typedef pair<long long, long long> node;

node e() {
    return {0, 0};
}

node op(node x, node y) {
    return {x.first + y.first, x.second + y.second};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, m;
    cin >> n >> k >> m;

    vector<vector<int>> changed(n + 1);
    vector<long long> cs(m), ps(m);

    for (int i = 0; i < m; i ++) {
        int l, r;
        cin >> l >> r >> cs[i] >> ps[i];
        changed[l - 1].emplace_back(i);
        changed[r].emplace_back(~i);
    }

    int M = 1e6 + 5;
    long long ans = 0;
    atcoder::segtree<node, op, e> seg(M);

    for (int i = 0; i < n; i ++) {
        for (auto idx: changed[i]) {
            if (idx >= 0) {
                auto [tot, cnt] = seg.get(ps[idx]);
                tot += ps[idx] * cs[idx];
                cnt += cs[idx];
                seg.set(ps[idx], {tot, cnt});
            }
            else {
                idx = ~idx;
                auto [tot, cnt] = seg.get(ps[idx]);
                tot -= ps[idx] * cs[idx];
                cnt -= cs[idx];
                seg.set(ps[idx], {tot, cnt});
            }
        }

        auto p = seg.max_right(0, [&] (node v) {return v.second < k;});
        if (p == M) ans += seg.all_prod().first;
        else {
            auto [tot, cnt] = seg.prod(0, p);
            ans += tot + (k - cnt) * p;
        }
    }

    cout << ans;

    return 0;
}