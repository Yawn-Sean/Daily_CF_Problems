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
// I came, I divided, I conquered!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, p, k;
    cin >> n >> p >> k;

    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; i ++)
        cin >> v1[i] >> v2[i];
    
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int i, int j) {return v2[i] > v2[j] ? 1 : (v2[i] == v2[j] && v1[i] < v1[j]);});

    map<int, vector<int>, greater<int>> mp;
    for (int i = 0; i < n - (p - k); i ++) {
        int idx = order[i];
        mp[v1[idx]].emplace_back(idx);
    }

    vector<int> used(n, 0);
    int chosen = 0;

    for (auto &[_, v]: mp) {
        for (auto &idx: v) {
            if (chosen < k) {
                cout << idx + 1 << ' ';
                chosen ++;
                used[idx] = 1;
            }
        }
    }

    int start = 0;
    for (int i = n - 1; i >= 0; i --) {
        int idx = order[i];
        if (used[idx]) {
            start = i + 1;
            break;
        }
    }

    mp.clear();

    for (int i = start; i < n; i ++) {
        int idx = order[i];
        mp[v2[idx]].emplace_back(idx);
    }

    for (auto &[_, v]: mp) {
        for (auto &idx: v) {
            if (chosen < p) {
                cout << idx + 1 << ' ';
                chosen ++;
                used[idx] = 1;
            }
        }
    }

    return 0;
}