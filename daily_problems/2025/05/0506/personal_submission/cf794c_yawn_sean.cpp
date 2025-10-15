#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/lazysegtree"
// #include "atcoder/fenwicktree"
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

    vector<int> c1(26, 0), c2(26, 0);

    cin >> s;

    for (auto &c: s)
        c1[c - 'a'] ++;
    
    cin >> s;

    for (auto &c: s)
        c2[c - 'a'] ++;
    
    vector<int> v1, v2;
    
    for (int i = 0; i < 26; i ++)
        for (int j = 0; j < c1[i]; j ++)
            v1.emplace_back(i);
    
    for (int i = 25; i >= 0; i --)
            for (int j = 0; j < c2[i]; j ++)
                v2.emplace_back(i);
    
    int n = s.size();
    vector<int> ans(n, 0);

    int l = 0, r = n - 1, cnt1 = (n + 1) / 2, cnt2 = n / 2, p1 = 0, p2 = 0;

    for (int idx = 0; idx < n; idx ++) {
        if (idx % 2 == 0) {
            if (v1[p1] < v2[p2]) ans[l ++] = v1[p1 ++];
            else ans[r --] = v1[p1 + cnt1 - 1];
            cnt1 --;
        }
        else {
            if (v1[p1] < v2[p2]) ans[l ++] = v2[p2 ++];
            else ans[r --] = v2[p2 + cnt2 - 1];
            cnt2 --;
        }
    }

    for (auto &x: ans) cout << (char)(x + 'a');

    return 0;
}