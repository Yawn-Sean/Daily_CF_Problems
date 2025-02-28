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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> path(n), rev_path(n);
    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
        rev_path[v].emplace_back(u);
    }

    int k;
    cin >> k;

    vector<int> nums(k);
    for (auto &x: nums)
        cin >> x, x --;
    
    int des = nums.back();
    vector<int> dis(n, -1), que(n);
    dis[des] = 0;

    int l = 0, r = 1;
    que[l] = des;

    while (l < r) {
        int u = que[l ++];
        for (auto &v: rev_path[u]) {
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                que[r ++] = v;
            }
        }
    }

    int v1 = 0, v2 = 0;
    for (int i = 0; i < k - 1; i ++) {
        int u = nums[i], v = nums[i + 1];
        if (dis[v] >= dis[u]) v1 ++, v2 ++;
        else {
            int c = 0;
            for (auto &x: path[u])
                c += dis[x] < dis[u];
            v2 += c > 1;
        }
    }

    cout << v1 << ' ' << v2;

    return 0;
}