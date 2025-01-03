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

    string s;
    cin >> s;

    vector<int> vis(26, -1);

    for (int i = 0; i < 27; i ++) {
        int c = s[i] - 'A';
        if (vis[c] == -1) vis[c] = i;
        else {
            if (vis[c] == i - 1) cout << "Impossible";
            else {
                int x = i - vis[c] - 1;
                vector<string> ans(2, string(13, ' '));

                for (int j = 0; j < x - x / 2; j ++) {
                    ans[0][j] = s[i - (x - x / 2 - j)];
                    ans[1][j] = s[vis[c] + x / 2 - j];
                }

                ans[1][x / 2] = s[i];
                int sx, sy;
                sx = 1, sy = x / 2;

                for (int j = vis[c] - 1; j >= 0; j --) {
                    sy += (sx ? 1 : -1);
                    if (sy >= 13) sx = 0, sy = 12;
                    ans[sx][sy] = s[j];
                }

                sx = 0, sy = x - x / 2 - 1;
                for (int j = i + 1; j < 27; j ++) {
                    sy += (sx ? -1 : 1);
                    if (sy >= 13) sx = 1, sy = 12;
                    ans[sx][sy] = s[j];
                }
                cout << ans[0] << '\n' << ans[1];
            }
            return 0;
        }
    }

    return 0;
}