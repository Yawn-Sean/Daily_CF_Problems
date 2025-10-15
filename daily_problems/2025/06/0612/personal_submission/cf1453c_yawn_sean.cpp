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

    int t;
    cin >> t;

    while (t--) {
       int n;
       cin >> n;

       vector<string> grid(n);
       for (auto &s: grid) cin >> s; 

       vector<int> min_x(10, n + 1), max_x(10, -1);
       vector<int> min_y(10, n + 1), max_y(10, -1);
       
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                int v = grid[i][j] - '0';
                min_x[v] = min(min_x[v], i);
                max_x[v] = max(max_x[v], i);
                min_y[v] = min(min_y[v], j);
                max_y[v] = max(max_y[v], j);
            }
        }

        vector<int> ans(10, 0);

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                int v = grid[i][j] - '0';
                ans[v] = max(ans[v], max(i, n - 1 - i) * max(max_y[v] - j, j - min_y[v]));
                ans[v] = max(ans[v], max(j, n - 1 - j) * max(max_x[v] - i, i - min_x[v]));
            }
        }

        for (auto &x: ans) cout << x << ' '; cout << '\n';
    }

    return 0;
}