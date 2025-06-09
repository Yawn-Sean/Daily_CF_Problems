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

    vector<vector<int>> tmp(n + 4);
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        tmp[x].emplace_back(i);
    }

    int cur = 0;
    vector<int> ans;

    for (int i = 0; i < n; i ++) {
        while (true) {
            if (tmp[cur].size()) {
                ans.emplace_back(tmp[cur].back());
                tmp[cur].pop_back();
                break;
            }
            else {
                if (cur < 3) return cout << "Impossible", 0;
                cur -= 3;
            }
        }
        cur ++;
    }

    cout << "Possible\n";
    for (auto &x: ans) cout << x + 1 << ' ';

    return 0;
}