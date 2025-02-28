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

    int n, k, s, t;
    cin >> n >> k >> s >> t;

    vector<pair<int, int>> cars(n);
    for (auto &[x, y]: cars)
        cin >> y >> x;
    
    sort(cars.begin(), cars.end());

    vector<int> stations(k + 2);
    for (int i = 1; i <= k; i ++)
        cin >> stations[i];
    
    stations[0] = 0, stations[k + 1] = s;
    sort(stations.begin(), stations.end());

    int l = 0, r = n - 1, inf = 2e9 + 10;

    while (l <= r) {
        int m = (l + r) / 2;
        int v = cars[m].first, total = 0;

        for (int i = 0; i <= k; i ++) {
            int dis = stations[i + 1] - stations[i];
            if (dis > v) {
                total = inf;
                break;
            }
            else total += 2 * dis - min(dis, v - dis);
        }

        if (total <= t) r = m - 1;
        else l = m + 1;
    }

    int ans = inf;
    for (int i = l; i < n; i ++)
        ans = min(ans, cars[i].second);
    
    cout << (ans < inf ? ans : -1);

    return 0;
}