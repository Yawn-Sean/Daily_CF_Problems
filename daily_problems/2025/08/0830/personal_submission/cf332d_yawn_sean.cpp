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

    int n, k;
    cin >> n >> k;

    vector<vector<int>> grid(n, vector<int>(n, -1));

    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            cin >> grid[i][j];
            grid[j][i] = grid[i][j];
        }
    }

    if (k == 2) {
        long long ans = 0;
        for (int i = 0; i < n; i ++) {
            long long tot = 0, cnt = 0;
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] != -1) {
                    cnt ++;
                    tot += grid[i][j];
                }
            }
            ans += (cnt - 1) * tot;
        }
        cout << ans / (1ll * n * (n - 1) / 2);
    }
    else {
        long long ans = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] != -1) {
                    ans += grid[i][j];
                }
            }
        }
        cout << ans / n;
    }

    return 0;
}