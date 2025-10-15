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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> tags(n);
    for (auto &v: tags)
        cin >> v;
    
    vector<vector<int>> path(n);
    vector<int> indegs(n, 0);

    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        path[u].emplace_back(v);
        indegs[v] ++;
    }

    vector<int> stk0, stk1;
    for (int i = 0; i < n; i ++) {
        if (!indegs[i]) {
            if (tags[i]) stk1.emplace_back(i);
            else stk0.emplace_back(i);
        }
    }

    int ans = 0;
    while (!stk0.empty() || !stk1.empty()) {
        while (!stk0.empty()) {
            int u = stk0.back();
            stk0.pop_back();
            for (auto &v: path[u]) {
                indegs[v] --;
                if (indegs[v] == 0) {
                    if (tags[v]) stk1.emplace_back(v);
                    else stk0.emplace_back(v);
                }
            }
        }
        if (stk1.size()) ans ++;
        while (!stk1.empty()) {
            int u = stk1.back();
            stk1.pop_back();
            for (auto &v: path[u]) {
                indegs[v] --;
                if (indegs[v] == 0) {
                    if (tags[v]) stk1.emplace_back(v);
                    else stk0.emplace_back(v);
                }
            }
        }
    }

    cout << ans;

    return 0;
}