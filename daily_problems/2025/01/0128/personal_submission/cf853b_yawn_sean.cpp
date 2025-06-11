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

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> froms(n + 1), tos(n + 1);

    while (m --) {
        int d, f, t, c;
        cin >> d >> f >> t >> c;
        if (f) froms[f].emplace_back(d, c);
        else tos[t].emplace_back(d, c);
    }

    long long inf = 1e13;
    int M = 1e6;

    vector<long long> ans1(M + 2, 0), ans2(M + 2, 0);

    for (int i = 1; i <= n; i ++) {
        sort(froms[i].begin(), froms[i].end());
        sort(tos[i].begin(), tos[i].end());

        int fk = froms[i].size(), tk = tos[i].size();

        if (fk == 0 || tk == 0) return cout << -1, 0;

        long long v;

        ans1[0] += inf;
        ans1[froms[i][0].first] -= inf;

        v = inf;
        for (int j = 0; j < fk - 1; j ++) {
            v = min(v, (long long)froms[i][j].second);
            ans1[froms[i][j].first] += v;
            ans1[froms[i][j + 1].first] -= v;
        }

        v = min(v, (long long)froms[i][fk - 1].second);
        ans1[froms[i][fk - 1].first] += v;
        ans1[M + 1] -= v;

        ans2[tos[i][tk - 1].first + 1] += inf;
        ans2[M + 1] -= inf;

        v = inf;
        for (int j = tk - 2; j >= 0; j --) {
            v = min(v, (long long)tos[i][j + 1].second);
            ans2[tos[i][j].first + 1] += v;
            ans2[tos[i][j + 1].first + 1] -= v;
        }

        v = min(v, (long long)tos[i][0].second);
        ans2[0] += v;
        ans2[tos[i][0].first + 1] -= v;
    }

    for (int i = 0; i <= M; i ++) {
        ans1[i + 1] += ans1[i];
        ans2[i + 1] += ans2[i];
    }

    long long ans = inf;
    for (int i = 0; i <= M + 1; i ++) {
        if (i + k + 1 <= M) {
            ans = min(ans, ans1[i] + ans2[i + k + 1]);
        }
    }

    cout << (ans < inf ? ans : -1);

    return 0;
}