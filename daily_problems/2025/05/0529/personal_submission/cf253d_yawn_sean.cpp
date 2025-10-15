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

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m, k;
    fin >> n >> m >> k;
    
    vector<string> grid(n);
    for (auto &s: grid) fin >> s;

    long long ans = 0;

    for (int i = 0; i < n; i ++) {
        vector<int> cnt(m, 0);
        for (int j = i; j < n; j ++) {
            for (int a = 0; a < m; a ++)
                if (grid[j][a] == 'a') cnt[a] ++;
            
            if (j > i) {
                int l = 0, cur = 0;
                vector<int> tmp(26, 0);

                for (int r = 0; r < m; r ++) {
                    cur += cnt[r];

                    while (cur > k) {
                        if (grid[i][l] == grid[j][l]) tmp[grid[i][l] - 'a'] --;
                        cur -= cnt[l];
                        l ++;
                    }

                    if (grid[i][r] == grid[j][r]) {
                        if (l < r) ans += tmp[grid[i][r] - 'a'];
                        tmp[grid[i][r] - 'a'] ++;
                    }
                }
            }
        }
    }
    fout << ans;

    return 0;
}