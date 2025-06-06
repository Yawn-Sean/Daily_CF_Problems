#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
// #include "atcoder/maxflow"
// #include "atcoder/mincostflow"
// #include "atcoder/modint"
// #include "atcoder/scc"
// #include "atcoder/segtree"
// #include "atcoder/string"
// #include "atcoder/twosat"
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

    map<int, int> mp;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        mp[x] ++;
    }

    priority_queue<pair<int, int>> pq;
    for (auto &[k, v]: mp)
        pq.push({v, k});

    vector<array<int, 3>> ans;

    while (pq.size() >= 3) {
        auto [c1, v1] = pq.top(); pq.pop();
        auto [c2, v2] = pq.top(); pq.pop();
        auto [c3, v3] = pq.top(); pq.pop();

        ans.push_back({v1, v2, v3});
        c1 --, c2 --, c3 --;

        if (c1) pq.push({c1, v1});
        if (c2) pq.push({c2, v2});
        if (c3) pq.push({c3, v3});
    }

    cout << ans.size() << '\n';
    for (auto &v: ans) {
        sort(v.begin(), v.end(), greater<int>());
        cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
    }

    return 0;
}