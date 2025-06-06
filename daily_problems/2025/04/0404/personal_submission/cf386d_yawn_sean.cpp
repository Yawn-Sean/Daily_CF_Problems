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

    auto order = [&] (int &x, int &y, int &z) -> void {
        if (x > y) swap(x, y);
        if (y > z) swap(y, z);
        if (x > y) swap(x, y);
    };

    int n, tx, ty, tz;
    cin >> n >> tx >> ty >> tz;
    tx --, ty --, tz --;

    order(tx, ty, tz);

    vector<string> grid(n);
    for (auto &s: grid) cin >> s;

    auto f = [&] (int x, int y, int z) -> int {
        return (x * n + y) * n + z;
    };

    vector<int> prev(n * n * n, -2);
    vector<pair<int, int>> trans(n * n * n);
    queue<array<int, 3>> q;

    q.push({0, 1, 2});
    prev[f(0, 1, 2)] = -1;

    while (!q.empty()) {
        auto [x, y, z] = q.front();
        q.pop();

        for (int nx = 0; nx < n; nx ++) {
            if (nx == x || nx == y || nx == z) continue;
            if (grid[x][nx] == grid[y][z]) {
                int a = nx, b = y, c = z;
                order(a, b, c);
                int nu = f(a, b, c);
                if (prev[nu] == -2) {
                    prev[nu] = f(x, y, z);
                    trans[nu] = {nx + 1, x + 1};
                    q.push({a, b, c});
                }
            }
        }

        for (int ny = 0; ny < n; ny ++) {
            if (ny == x || ny == y || ny == z) continue;
            if (grid[y][ny] == grid[x][z]) {
                int a = x, b = ny, c = z;
                order(a, b, c);
                int nu = f(a, b, c);
                if (prev[nu] == -2) {
                    prev[nu] = f(x, y, z);
                    trans[nu] = {ny + 1, y + 1};
                    q.push({a, b, c});
                }
            }
        }

        for (int nz = 0; nz < n; nz ++) {
            if (nz == x || nz == y || nz == z) continue;
            if (grid[z][nz] == grid[x][y]) {
                int a = x, b = y, c = nz;
                order(a, b, c);
                int nu = f(a, b, c);
                if (prev[nu] == -2) {
                    prev[nu] = f(x, y, z);
                    trans[nu] = {nz + 1, z + 1};
                    q.push({a, b, c});
                }
            }
        }
    }

    int cur = f(tx, ty, tz);
    if (prev[cur] == -2) cout << -1;
    else {
        vector<pair<int, int>> ans;
        while (cur != f(0, 1, 2)) {
            ans.emplace_back(trans[cur]);
            cur = prev[cur];
        }
        cout << ans.size() << '\n';
        for (auto &[x, y]: ans)
            cout << x << ' ' << y << '\n';
    }

    return 0;
}