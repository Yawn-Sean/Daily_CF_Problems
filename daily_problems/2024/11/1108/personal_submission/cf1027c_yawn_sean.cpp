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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;
        map<int, int> mp;

        while (n --) {
            int x;
            cin >> x;
            mp[x] ++;
        }

        bool flg = false;
        vector<int> tmp;
        for (auto &[k, v]: mp) {
            if (v >= 4) {
                cout << k << ' ' << k << ' ' << k << ' ' << k << '\n';
                flg = true;
                break;
            }
            if (v >= 2) tmp.emplace_back(k);
        }

        if (!flg) {
            sort(tmp.begin(), tmp.end());
            int x = 1, y = 0;
            for (int i = 1; i < tmp.size(); i ++) {
                int nx = tmp[i], ny = tmp[i - 1];
                if (nx * y < x * ny)
                    x = nx, y = ny;
            }
            cout << x << ' ' << x << ' ' << y << ' ' << y << '\n';
        }
    }

    return 0;
}