#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int cur_max = 0;
    map<pair<int, int>, int> saved;

    auto query = [&] (int x, int y) -> int {
        if (x == 0 || x == n + 1) return 0;
        if (y == 0 || y == n + 1) return 0;

        if (saved.find({x, y}) != saved.end()) return saved[{x, y}];

        cout << "? " << x << ' ' << y << endl;
        int res;
        cin >> res;
        cur_max = max(cur_max, res);
        saved[{x, y}] = res;
        return res;
    };

    auto solve = [&] (auto &self, int xl, int xr, int yl, int yr) -> void {

        int xm = (xl + xr) / 2;
        int ym = (yl + yr) / 2;

        int val = 0, vx, vy;

        for (int x = xl; x <= xr; x ++) {
            int nval;
            nval = query(x, ym);
            if (nval > val) {
                val = nval;
                vx = x;
                vy = ym;
            }
            nval = query(x, yl - 1);
            if (nval > val) {
                val = nval;
                vx = x;
                vy = yl - 1;
            }
            nval = query(x, yr + 1);
            if (nval > val) {
                val = nval;
                vx = x;
                vy = yr + 1;
            }
        }

        for (int y = yl; y <= yr; y ++) {
            int nval;
            nval = query(xm, y);
            if (nval > val) {
                val = nval;
                vx = xm;
                vy = y;
            }
            nval = query(xl - 1, y);
            if (nval > val) {
                val = nval;
                vx = xl - 1;
                vy = y;
            }
            nval = query(xr + 1, y);
            if (nval > val) {
                val = nval;
                vx = xr + 1;
                vy = y;
            }
        }

        vector<pair<int, int>> dirs = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
        };
        for (auto &[dx, dy]: dirs) {
            int nx = vx + dx, ny = vy + dy;
            if (nx >= xl && nx <= xr && ny >= yl && ny <= yr && query(nx, ny) > val) {
                if (nx > xm) {
                    if (ny > ym) self(self, xm + 1, xr, ym + 1, yr);
                    else self(self, xm + 1, xr, yl, ym - 1);
                }
                else {
                    if (ny > ym) self(self, xl, xm - 1, ym + 1, yr);
                    else self(self, xl, xm - 1, yl, ym - 1);
                }
            }
        }
    };

    solve(solve, 1, n, 1, n);
    cout << "! " << cur_max;

    return 0;
}