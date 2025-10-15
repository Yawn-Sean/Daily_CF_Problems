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

    string s;
    cin >> s;

    int n = s.size();
    map<char, vector<int>> mp;

    for (int i = 0; i < n; i ++)
        mp[s[i]].emplace_back(i);

    int ans = 0;
    for (auto &[k, v]: mp) {
        int res = 0;
        for (int p = 0; p < n; p ++) {
            map<char, int> cnt;
            for (auto &x: v)
                cnt[s[(x + p) % n]] ++;
            
            int cur = 0;
            for (auto &[_, c]: cnt) 
                cur += (c == 1);
            
            res = max(res, cur);
        }
        ans += res;
    }

    cout << fixed << setprecision(10) << (long double)1.0 * ans / n;

    return 0;
}