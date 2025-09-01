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

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &s: grid) cin >> s;

    int ans = 0;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            int v = grid[i][j];
            if (i + 1 < n) v -= grid[i + 1][j];
            if (j + 1 < m) v -= grid[i][j + 1];
            if (i + 1 < n && j + 1 < m) v += grid[i + 1][j + 1];

            if (v) ans ++;
        }
    }

    cout << ans;

    return 0;
}