#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

// Let's flow!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> ms(n), ks(n);
    for (int i = 0; i < n; i ++)
        cin >> ms[i] >> ks[i];

    int x = 0, y = 1;
    for (int c = 1; c <= min(20, n); c ++) {
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i ++)
            mp[ms[i]] += min(ks[i], c);
        
        vector<int> tmp;
        for (auto &[k, v]: mp) tmp.emplace_back(v);
        sort(tmp.rbegin(), tmp.rend());

        int tot = 0;
        for (int i = 0; i < min(c, (int)tmp.size()); i ++)
            tot += tmp[i];
        
        if (tot * y > x * c) {
            x = tot;
            y = c;
        }
    }

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i ++)
        mp[ms[i]] += min(ks[i], y);
    
    vector<int> ids;
    for (auto &[k, v]: mp) ids.emplace_back(k);

    sort(ids.begin(), ids.end(), [&](int i, int j) {return mp[i] > mp[j];});

    cout << y << '\n';
    for (int i = 0; i < y; i ++)
        cout << ids[i] << ' ';

    return 0;
}