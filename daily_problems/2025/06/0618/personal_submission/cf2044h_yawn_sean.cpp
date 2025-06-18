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
        int n, q;
        cin >> n >> q;

        vector<vector<long long>> pref_orig(n + 1, vector<long long>(n + 1, 0));
        vector<vector<long long>> pref_x(n + 1, vector<long long>(n + 1, 0));
        vector<vector<long long>> pref_y(n + 1, vector<long long>(n + 1, 0));

        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                cin >> pref_orig[i][j];
                pref_x[i][j] = pref_orig[i][j] * i;
                pref_y[i][j] = pref_orig[i][j] * j;
            }
        }

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j <= n; j ++) {
                pref_orig[i + 1][j] += pref_orig[i][j];
                pref_x[i + 1][j] += pref_x[i][j];
                pref_y[i + 1][j] += pref_y[i][j];
            }
        }

        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j < n; j ++) {
                pref_orig[i][j + 1] += pref_orig[i][j];
                pref_x[i][j + 1] += pref_x[i][j];
                pref_y[i][j + 1] += pref_y[i][j];
            }
        }

        while (q --) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            long long orig = pref_orig[x2][y2] - pref_orig[x1 - 1][y2] - pref_orig[x2][y1 - 1] + pref_orig[x1 - 1][y1 - 1];
            long long vx = pref_x[x2][y2] - pref_x[x1 - 1][y2] - pref_x[x2][y1 - 1] + pref_x[x1 - 1][y1 - 1];
            long long vy = pref_y[x2][y2] - pref_y[x1 - 1][y2] - pref_y[x2][y1 - 1] + pref_y[x1 - 1][y1 - 1];

            cout << vx * (y2 - y1 + 1) + vy + (1 - y1 - x1 * (y2 - y1 + 1)) * orig << ' ';
        }
        cout << '\n';
    }

    return 0;
}