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

    while (t --) {
        int n, w, l;
        cin >> n >> w >> l;

        vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));

        while (w --) {
            int x, y;
            cin >> x >> y;
            grid[x][y] = 1;
        }

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j <= n; j ++) {
                grid[i + 1][j] += grid[i][j];
            }
        }

        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j < n; j ++) {
                grid[i][j + 1] += grid[i][j];
            }
        }

        vector<vector<int>> ans(n + 1, vector<int>(n + 1, 0));
        int res = 0;

        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                int v = ans[i - 1][j - 1] + 1;

                while (grid[i][j] - grid[i - v][j] - grid[i][j - v] + grid[i - v][j - v] > l) v --;

                ans[i][j] = v, res = max(res, v);
            }
        }

        cout << res * res << '\n';
    }

    return 0;
}