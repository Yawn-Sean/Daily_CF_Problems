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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, T;
    cin >> n >> T;

    priority_queue<pair<int, int>> pq;

    while (n --) {
        int t, q;
        cin >> t >> q;
        pq.push({T - t, q});
    }

    while (pq.top().first > 0) {
        auto [t, q] = pq.top();
        pq.pop();
        if (pq.size() && pq.top().first == t) {
            auto [t1, q1] = pq.top();
            pq.pop();
            q += q1;
        }
        pq.push({t - 1, q});
    }

    cout << pq.top().second;

    return 0;
}