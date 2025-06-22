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

    string s;
    cin >> s;

    int n = s.size(), k;
    cin >> k;

    vector<vector<bool>> dp(2, vector<bool>((k + 1) * (2 * n + 1), 0));

    auto f = [&] (int i, int j) -> int {
        return i * (2 * n + 1) + j;
    };

    dp[0][f(0, n)] = 1;

    for (auto &c: s) {
        vector<vector<bool>> ndp(2, vector<bool>((k + 1) * (2 * n + 1), 0));

        if (c == 'T') {
            for (int i = 0; i < 2; i ++) {
                for (int x = 0; x <= k; x ++) {
                    for (int y = 0; y <= 2 * n; y ++) {
                        if (dp[i][f(x, y)]) {
                            ndp[i ^ 1][f(x, y)] = 1;
                            if (x < k) {
                                ndp[i][f(x + 1, y + (i ? -1 : 1))] = 1;
                            }
                        }
                    }
                }
            }
        }
        else {
            for (int i = 0; i < 2; i ++) {
                for (int x = 0; x <= k; x ++) {
                    for (int y = 0; y <= 2 * n; y ++) {
                        if (dp[i][f(x, y)]) {
                            ndp[i][f(x, y + (i ? -1 : 1))] = 1;
                            if (x < k) {
                                ndp[i ^ 1][f(x + 1, y)] = 1;
                            }
                        }
                    }
                }
            }
        }
        dp.swap(ndp);
    }

    int ans = 0;
    for (int i = 0; i < 2; i ++) {
        for (int x = 0; x <= k; x ++) {
            for (int y = 0; y <= 2 * n; y ++) {
                if (dp[i][f(x, y)] && (k - x) % 2 == 0) {
                    ans = max(ans, abs(y - n));
                }
            }
        }
    }

    cout << ans;

    return 0;
}