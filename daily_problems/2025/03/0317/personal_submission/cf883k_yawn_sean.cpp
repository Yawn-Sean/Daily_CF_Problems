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

    int n;
    cin >> n;

    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; i ++) {
        int s, g;
        cin >> s >> g;
        v1[i] = s;
        v2[i] = s + g;
    }

    for (int i = 1; i < n; i ++)
        v2[i] = min(v2[i], v2[i - 1] + 1);
    
    for (int i = n - 2; i >= 0; i --)
        v2[i] = min(v2[i], v2[i + 1] + 1);
    
    bool flg = true;
    long long res = 0;

    for (int i = 0; i < n; i ++) {
        res += v2[i] - v1[i];
        if (v2[i] < v1[i]) flg = false;
    }

    if (!flg) cout << -1;
    else {
        cout << res << '\n';
        for (auto &x: v2) cout << x << ' ';
    }

    return 0;
}