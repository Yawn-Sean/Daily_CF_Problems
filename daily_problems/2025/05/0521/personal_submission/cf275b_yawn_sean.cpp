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

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &s: grid) cin >> s;

    for (int i = 0; i < n; i ++) {
        char cur = 'W';
        int blocks = 1;
        for (int j = 0; j < m; j ++)
            if (grid[i][j] != cur)
                cur = grid[i][j], blocks ++;
        
        if (blocks >= 4) return cout << "NO", 0;
    }

    
    for (int j = 0; j < m; j ++) {
        char cur = 'W';
        int blocks = 1;
        for (int i = 0; i < n; i ++)
            if (grid[i][j] != cur)
                cur = grid[i][j], blocks ++;
        
        if (blocks >= 4) return cout << "NO", 0;
    }

    for (int i1 = 0; i1 < n; i1 ++) {
        for (int j1 = 0; j1 < m; j1 ++) {
            for (int i2 = 0; i2 < n; i2 ++) {
                for (int j2 = 0; j2 < m; j2 ++) {
                    if (grid[i1][j1] == 'B' && grid[i2][j2] == 'B' && grid[i1][j2] == 'W' && grid[i2][j1] == 'W') {
                        return cout << "NO", 0;
                    }
                }
            }
        }
    }

    cout << "YES";

    return 0;
}