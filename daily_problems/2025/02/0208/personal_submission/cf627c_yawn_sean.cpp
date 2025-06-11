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
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divide, I conquer!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int d, n, m;
    cin >> d >> n >> m;

    vector<pair<int, int>> stations(m + 2);
    stations[0] = {0, 0};
    stations[m + 1] = {d, 0};

    for (int i = 1; i <= m; i ++)
        cin >> stations[i].first >> stations[i].second;

    sort(stations.begin(), stations.end());

    vector<int> stk = {m + 1}, choice(m + 1, -1);
    for (int i = m; i >= 0; i --) {
        while (stations[stk.back()].second > stations[i].second)
            stk.pop_back();
        choice[i] = stk.back();
        stk.emplace_back(i);
    }

    long long ans = 0;
    int cur = n;

    for (int i = 0; i <= m; i ++) {
        int d = max(0, min(n, stations[choice[i]].first - stations[i].first) - cur);
        ans += 1ll * d * stations[i].second;
        cur += d - (stations[i + 1].first - stations[i].first);
        if (cur < 0) return cout << -1, 0;
    }
    cout << ans;

    return 0;
}