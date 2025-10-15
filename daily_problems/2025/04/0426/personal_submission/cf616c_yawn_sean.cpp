#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
#include "atcoder/dsu"
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

    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    for (auto &s: grid) cin >> s;

    atcoder::dsu uf(n * m);

    auto f = [&] (int i, int j) -> int {return i * m + j;};

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == '.') {
                if (i && grid[i - 1][j] == '.') uf.merge(f(i, j), f(i - 1, j));
                if (j && grid[i][j - 1] == '.') uf.merge(f(i, j), f(i, j - 1));
            }
        }
    }

    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == '*') {
                set<int> st;
                int res = 1;
                for (auto &[di, dj]: dirs) {
                    if (i + di >= 0 && i + di < n && j + dj >= 0 && j + dj < m && grid[i + di][j + dj] == '.') {
                        int lead = uf.leader(f(i + di, j + dj));
                        if (st.find(lead) == st.end()) {
                            st.insert(lead);
                            res += uf.size(f(i + di, j + dj));
                            res %= 10;
                        }
                    }
                }
                grid[i][j] = '0' + res;
            }
        }
    }

    for (auto &s: grid) cout << s << '\n';

    return 0;
}