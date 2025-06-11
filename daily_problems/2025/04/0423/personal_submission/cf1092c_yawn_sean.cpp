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

    int n;
    cin >> n;

    vector<string> strs(2 * n - 2);
    for (auto &s: strs) cin >> s;

    map<string, vector<int>> mp;
    for (int i = 0; i < 2 * n - 2; i ++)
        mp[strs[i]].emplace_back(i);

    vector<int> tmp;
    for (int i = 0; i < 2 * n - 2; i ++)
        if (strs[i].size() == n - 1)
            tmp.emplace_back(i);
    
    string s1 = strs[tmp[0]], s2 = strs[tmp[1]];
    string ans(2 * n - 2, ' ');

    auto check = [&] (string s) -> void {
        map<string, vector<bool>> cnt;
        for (int i = 1; i < n; i ++) {
            cnt[s.substr(0, i)].emplace_back(1);
            cnt[s.substr(n - i, i)].emplace_back(0);
        }

        for (auto &[k, v]: mp) {
            if (cnt[k].size() != v.size()) {
                return ;
            }
        }

        for (auto &[k, v]: mp) {
            for (int i = 0; i < v.size(); i ++) {
                ans[v[i]] = (cnt[k][i] ? 'P' : 'S');
            }
        }

        cout << ans;
        exit(0);
    };

    check(s1 + s2.back());
    check(s2 + s1.back());

    return 0;
}