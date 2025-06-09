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

    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<string> strs(n);
    for (auto &x: strs) cin >> x;

    int start = 0, length = 0, mi_start = 0;

    for (int i = 0; i < s.size(); i ++) {
        for (auto &x: strs) {
            if (i + 1 >= x.size() && s.substr(i + 1 - x.size(), x.size()) == x) {
                mi_start = max(mi_start, i + 1 - (int)x.size() + 1);
            }
        }
        if (i - mi_start + 1 > length) {
            start = mi_start;
            length = i - mi_start + 1;
        }
    }

    cout << length << ' ' << start;

    return 0;
}