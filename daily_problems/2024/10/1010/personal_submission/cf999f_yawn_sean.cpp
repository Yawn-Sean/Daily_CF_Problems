#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, M = 1e5;
    cin >> n >> k;

    vector<int> cnt(M + 1, 0), player_cnt(M + 1, 0);

    for (int i = 0; i < n * k; i ++) {
        int c;
        cin >> c;
        cnt[c] ++;
    }

    for (int i = 0; i < n; i ++) {
        int c;
        cin >> c;
        player_cnt[c] ++;
    }

    vector<int> hs(k);
    for (auto &h: hs) cin >> h;

    vector<vector<int>> dp(n + 1, vector<int>(n * k + 1, 0));
    for (int i = 1; i <= n; i ++) {
        for (int j = n * k; j > 0; j --) {
            for (int v = 0; v < k; v ++) {
                if (j - v - 1 >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - v - 1] + hs[v]);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= M; i ++) {
        ans += dp[player_cnt[i]][cnt[i]];
    }
    
    cout << ans;

    return 0;
}
