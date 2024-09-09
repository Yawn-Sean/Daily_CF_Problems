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

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> values(n), cnt(1 << n, 0);

    for (auto &v: values) cin >> v;
    while (m --) {
        string s;
        cin >> s;
        int msk = 0;
        for (auto c: s) msk = msk * 2 + c - '0';
        cnt[msk] ++;
    }

    vector<int> dp(1 << n, 0);
    for (int i = 1; i < 1 << n; i ++) {
        int x = i & -i;
        dp[i] = dp[i - x] + values[n - (32 - __builtin_clz(x))];
    }

    vector<vector<int>> ans(101, vector<int>(1 << n));
    int tot_msk = (1 << n) - 1;

    for (int x = 0; x < 1 << n; x ++) {
        for (int y = 0; y < 1 << n; y ++) {
            if (dp[tot_msk - (x ^ y)] <= 100)
                ans[dp[tot_msk - (x ^ y)]][x] += cnt[y];
        }
        for (int y = 0; y < 100; y ++)
            ans[y + 1][x] += ans[y][x];
    }

    while (q --) {
        string s;
        int k;
        cin >> s >> k;
        int msk = 0;
        for (auto c: s) msk = msk * 2 + c - '0';
        cout << ans[k][msk]<< '\n';
    }

    return 0;
}