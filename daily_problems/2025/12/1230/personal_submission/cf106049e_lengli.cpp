#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<long long> outs;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<vector<long long>> grid(n, vector<long long>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];

        vector<long long> saved(2 * n - 1, 0);
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        while (q--) {
            int k;
            long long v;
            cin >> k >> v;
            k -= 2;   

            if (saved[k] != 0) {
                dp[n - 1][n - 1] += (v - saved[k]);
                saved[k] = v;
            } else {
                saved[k] = v;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (saved[i + j] > 0)
                            grid[i][j] = saved[i + j];
                        dp[i][j] = grid[i][j];
                    }
                }
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        long long w = 0;
                        if (i) w = max(w, dp[i - 1][j]);
                        if (j) w = max(w, dp[i][j - 1]);
                        dp[i][j] += w;
                    }
                }
            }

            outs.push_back(dp[n - 1][n - 1]);
        }
    }

    for (size_t i = 0; i < outs.size(); i++) {
        cout << outs[i];
        if (i + 1 < outs.size()) cout << '\n';
    }

    return 0;
}
