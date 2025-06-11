#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
#include "atcoder/dsu"
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
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
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

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<bool>> vis(n + 2, vector<bool>(m + 2, 0));
    vector<atcoder::dsu> ufs(n + 2, atcoder::dsu(m + 2));

    vector<int> cnt(n + 2, 0);
    atcoder::dsu uf(n + 2);

    vector<vector<int>> ls(n + 2, vector<int>(m + 2)), rs(n + 2, vector<int>(m + 2));
    for (auto &x: ls) iota(x.begin(), x.end(), 0);
    for (auto &x: rs) iota(x.begin(), x.end(), 0);

    vector<int> l(n + 2), r(n + 2);
    iota(l.begin(), l.end(), 0);
    iota(r.begin(), r.end(), 0);

    while (q --) {
        int x, y;
        cin >> x >> y;

        int cur = n + m + 2, cx, cy;
        
        int vx, vy;

        auto check = [&] () -> void {
            if (vy >= 1 && vy <= m) {
                int d = abs(vx - x) + abs(vy - y);
                if (d < cur || (d == cur && (vx < cx || (vx == cx && vy < cy))))
                    cur = d, cx = vx, cy = vy;
            }
        };

        auto operate = [&] (int x, int y1, int y2) -> void {
            int pl = min(ls[x][ufs[x].leader(y1)], ls[x][ufs[x].leader(y2)]);
            int pr = max(rs[x][ufs[x].leader(y1)], rs[x][ufs[x].leader(y2)]);
            ufs[x].merge(y1, y2);
            int y = ufs[x].leader(y1);
            ls[x][y] = pl;
            rs[x][y] = pr;
        };

        auto operate1 = [&] (int x1, int x2) -> void {
            int pl = min(l[uf.leader(x1)], l[uf.leader(x2)]);
            int pr = max(r[uf.leader(x1)], r[uf.leader(x2)]);
            uf.merge(pl, pr);
            int x = uf.leader(x1);
            l[x] = pl;
            r[x] = pr;
        };

        vx = x;
        while (vx && abs(vx - x) <= cur) {
            if (!vis[vx][y]) {
                vy = y;
                check();
                break;
            }

            int p = ufs[vx].leader(y);

            vy = ls[vx][p] - 1;
            check();

            vy = rs[vx][p] + 1;
            check();

            vx = l[uf.leader(vx - 1)];
        }

        vx = x;

        while (vx <= n && abs(vx - x) <= cur) {
            if (!vis[vx][y]) {
                vy = y;
                check();
                break;
            }

            int p = ufs[vx].leader(y);

            vy = ls[vx][p] - 1;
            check();

            vy = rs[vx][p] + 1;
            check();

            vx = r[uf.leader(vx + 1)];
        }

        cout << cx << ' ' << cy << '\n';

        vis[cx][cy] = 1;

        if (vis[cx][cy - 1]) operate(cx, cy, cy - 1);
        if (vis[cx][cy + 1]) operate(cx, cy, cy + 1);

        cnt[cx] ++;

        if (cnt[cx] == m) {
            if (cnt[cx - 1] == m) operate1(cx, cx - 1);
            if (cnt[cx + 1] == m) operate1(cx, cx + 1);
        }
    }

    return 0;
}