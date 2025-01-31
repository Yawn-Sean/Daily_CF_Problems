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

    int n, k;
    cin >> n >> k;

    map<string, vector<int>> mp;
    while (n --) {
        string s;
        int v;
        cin >> s >> v;
        mp[s].emplace_back(v);
    }

    for (auto &[k, v]: mp)
        sort(v.begin(), v.end());
    
    int ans = 0, mid = 0;

    for (auto &[s, v]: mp) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());

        if (s == rev_s) {
            while (v.size() > 1 && v[v.size() - 1] + v[v.size() - 2] > 0) {
                ans += v[v.size() - 1] + v[v.size() - 2];
                mid = max(mid, -v[v.size() - 2]);
                v.pop_back(), v.pop_back();
            }

            if (v.size()) mid = max(mid, v.back());
        }
        else if (mp.find(rev_s) != mp.end()) {
            auto &v1 = mp[rev_s];
            while (!v.empty() && !v1.empty() && v.back() + v1.back() > 0) {
                ans += v.back() + v1.back();
                v.pop_back(), v1.pop_back();
            }
        }
    }
    cout << ans + mid;

    return 0;
}