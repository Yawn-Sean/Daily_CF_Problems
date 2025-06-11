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

    int n, m, b;
    cin >> n >> m >> b;

    vector<int> costs(n), monitors(n), msks(n);

    for (int i = 0; i < n; i ++) {
        cin >> costs[i] >> monitors[i];
        int l;
        cin >> l;
        while (l --) {
            int x;
            cin >> x;
            msks[i] |= 1 << x - 1;
        }
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int i, int j) {return monitors[i] < monitors[j];});

    long long inf = 2e18, ans = inf;
    vector<long long> dp(1 << m, inf);
    dp[0] = 0;

    for (auto &x: order) {
        for (int i = 0; i < 1 << m; i ++) {
            dp[i | msks[x]] = min(dp[i | msks[x]], dp[i] + costs[x]);
        }
        ans = min(ans, dp[(1 << m) - 1] + 1ll * b * monitors[x]);
    }
    cout << (ans < inf ? ans : -1);

    return 0;
}