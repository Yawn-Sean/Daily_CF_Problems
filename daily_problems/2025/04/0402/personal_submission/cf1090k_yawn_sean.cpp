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

    map<pair<int, string>, vector<int>> mp;

    for (int i = 1; i <= n; i ++) {
        string s1, s2;
        cin >> s1 >> s2;

        int msk = 0;
        for (auto &c: s2)
            msk |= 1 << c - 'a';
        
        int idx = s1.size() - 1;
        while (idx >= 0 && (msk >> (s1[idx] - 1) & 1))
            idx --;
        
        s1 = s1.substr(0, idx + 1);
        mp[{msk, s1}].emplace_back(i);
    }

    cout << mp.size() << '\n';
    for (auto &[_, v]: mp) {
        cout << v.size() << ' ';
        for (auto &x: v) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}