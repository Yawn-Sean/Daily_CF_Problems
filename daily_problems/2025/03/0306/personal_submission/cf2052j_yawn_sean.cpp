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

    int t;
    cin >> t;

    while (t --) {
        int n, m, q;
        cin >> n >> m >> q;

        vector<long long> time(n), deadline(n), to_watch(m);

        for (auto &v: time) cin >> v;
        for (auto &v: deadline) cin >> v;
        for (auto &v: to_watch) cin >> v;

        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&] (int i, int j) {return deadline[i] < deadline[j];});

        vector<long long> acc(n, 0), saved(n, 0);

        for (int i = 0; i < n; i ++) {
            int u = order[i];
            acc[i] = time[u];
            if (i) acc[i] += acc[i - 1];
            saved[i] = deadline[u] - acc[i];
        }

        for (int i = n - 2; i >= 0; i --)
            saved[i] = min(saved[i], saved[i + 1]);

        for (int i = 1; i < m; i ++)
            to_watch[i] += to_watch[i - 1];
        
        sort(deadline.begin(), deadline.end());

        while (q --) {
            long long val;
            cin >> val;
            int p = lower_bound(deadline.begin(), deadline.end(), val) - deadline.begin();
            long long v = val;
            if (p < n) v = min(v, saved[p]);
            if (p) v = min(v, val - acc[p - 1]);
            cout << (upper_bound(to_watch.begin(), to_watch.end(), v) - to_watch.begin()) << ' ';
        }
        cout << '\n';
    }

    return 0;
}