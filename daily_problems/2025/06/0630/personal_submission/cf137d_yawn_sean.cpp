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
    int k;

    cin >> s >> k;

    int n = s.size();

    vector<vector<int>> change(n, vector<int>(n, 0));
    for (int diff = 1; diff < n; diff ++) {
        for (int l = 0; l < n - diff; l ++) {
            int r = l + diff;
            change[l][r] = change[l + 1][r - 1] + (s[l] != s[r]);
        }
    }

    vector<vector<int>> dp(k, vector<int>(n, n + 1)), pre(k, vector<int>(n, -1));

    for (int i = 0; i < n; i ++)
        dp[0][i] = change[0][i];
    
    for (int i = 0; i < k - 1; i ++) {
        for (int j = 0; j < n - 1; j ++) {
            for (int nj = j + 1; nj < n; nj ++) {
                if (dp[i][j] + change[j + 1][nj] < dp[i + 1][nj]) {
                    dp[i + 1][nj] = dp[i][j] + change[j + 1][nj];
                    pre[i + 1][nj] = j;
                }
            }
        }
    }

    int v = n + 1, chosen = -1;
    for (int i = 0; i < k; i ++) {
        if (dp[i][n - 1] < v) {
            v = dp[i][n - 1];
            chosen = i;
        }
    }

    vector<string> ans;
    int cur = n - 1;

    for (int i = chosen; i >= 0; i --) {
        int ncur = pre[i][cur];

        int l = ncur + 1, r = cur;
        while (l < r) {
            s[l] = s[r];
            l ++, r --;
        }

        ans.push_back(s.substr(ncur + 1, cur - ncur));
        cur = ncur;
    }

    reverse(ans.begin(), ans.end());

    cout << v << '\n';
    for (int i = 0; i < ans.size(); i ++) {
        if (i) cout << '+';
        cout << ans[i];
    }

    return 0;
}