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

    map<char, pair<int, int>> mp;
    mp['L'] = {-1, 0};
    mp['R'] = {1, 0};
    mp['D'] = {0, -1};
    mp['U'] = {0, 1};

    int t;
    cin >> t;

    while (t --) {
        string s;
        cin >> s;

        int x = 0, y = 0, cx = 0, cy = 0;
        for (auto &c: s) {
            auto &[dx, dy] = mp[c];
            cx += dx;
            cy += dy;

            if (cx || cy) {
                int vx = 0, vy = 0;
                
                for (auto &nc: s) {
                    auto &[tx, ty] = mp[nc];
                    if (vx + tx != cx || vy + ty != cy) {
                        vx += tx;
                        vy += ty;
                    }
                }

                if (!vx && !vy)
                    x = cx, y = cy;
            }
        }

        cout << x << ' ' << y << '\n';
    }

    return 0;
}