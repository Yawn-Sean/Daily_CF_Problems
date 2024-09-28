#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;

    cin >> n >> s;

    vector<int> ques(n + 1, 0);

    for (int i = 0; i < n; i ++) {
        ques[i + 1] = ques[i] + (s[i] == '?');
    }

    int mod = 998244353;

    vector<vector<int>> pows(18, vector<int>(n + 1, 1));

    for (int i = 1; i <= 17; i ++) {
        for (int j = 0; j < n; j ++) {
            pows[i][j + 1] = 1ll * pows[i][j] * i % mod;
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, 0)), cnt(n, vector<int>(n, 0));

    for (int l = n - 1; l >= 0; l --) {
        if (s[l] == '?') cnt[l][l] = 1;

        for (int r = l + 1; r < n; r ++) {
            if (dp[l + 1][r - 1] == -1 || (s[l] != '?' && s[r] != '?' && s[l] != s[r]))
                dp[l][r] = -1;
            else {
                dp[l][r] = dp[l + 1][r - 1];
                cnt[l][r] = cnt[l + 1][r - 1];

                if (s[l] != '?' && s[r] == '?')
                    dp[l][r] |= 1 << s[l] - 'a';
                else if (s[l] == '?' && s[r] != '?')
                    dp[l][r] |= 1 << s[r] - 'a';
                else if (s[l] == '?' && s[r] == '?')
                    cnt[l][r] ++;
            }
        }
    }

    vector<vector<int>> calc(18, vector<int>(1 << 17, 0));

    for (int l = 0; l < n; l ++) {
        for (int r = l; r < n; r ++) {
            if (dp[l][r] != -1) {
                for (int i = 1; i <= 17; i ++) {
                    calc[i][dp[l][r]] += pows[i][cnt[l][r] + ques[l] + ques[n] - ques[r + 1]];
                    if (calc[i][dp[l][r]] >= mod) calc[i][dp[l][r]] -= mod;
                }
            }
        }
    }

    for (int i = 1; i <= 17; i ++) {
        for (int j = 0; j < 17; j ++) {
            for (int msk = 0; msk < (1 << 17); msk ++) {
                if ((msk >> j) & 1) {
                    calc[i][msk] += calc[i][msk ^ (1 << j)];
                    if (calc[i][msk] >= mod) calc[i][msk] -= mod;
                }
            }
        }
    }

    int q;
    cin >> q;

    while (q --) {
        string s;
        cin >> s;
        int msk = 0;
        for (auto &c: s)
            msk |= 1 << c - 'a';
        cout << calc[s.size()][msk] << '\n';
    }

    return 0;
}