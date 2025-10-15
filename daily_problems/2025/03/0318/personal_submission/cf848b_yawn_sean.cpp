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

    int n, w, h;
    cin >> n >> w >> h;

    vector<int> gs(n), ps(n), ts(n);
    for (int i = 0; i < n; i ++)
        cin >> gs[i] >> ps[i] >> ts[i];

    map<int, vector<int>> mp;
    vector<pair<int, int>> ans(n);

    for (int i = 0; i < n; i ++)
        mp[ps[i] - ts[i]].emplace_back(i);
    
    for (auto &[k, v]: mp) {
        vector<int> v1, v2;
        
        for (auto &i: v) {
            if (gs[i] == 1) v1.emplace_back(i);
            else v2.emplace_back(i);
        }

        sort(v1.begin(), v1.end(), [&] (int i, int j) {return ps[i] < ps[j];});
        sort(v2.begin(), v2.end(), [&] (int i, int j) {return ps[i] > ps[j];});

        for (int i = 0; i < v.size(); i ++) {
            int start = (i < v2.size() ? v2[i] : v1[i - v2.size()]);
            int end = (i < v1.size() ? v1[i] : v2[i - v1.size()]);

            ans[start] = (gs[end] == 1 ? make_pair(ps[end], h) : make_pair(w, ps[end]));
        }
    }

    for (auto &[x, y]: ans)
        cout << x << ' ' << y << '\n';

    return 0;
}