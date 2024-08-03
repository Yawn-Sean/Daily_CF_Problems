#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, mod;
    cin >> n >> mod;

    vector<int> dp(n + 1), dp_acc(n + 1), prime_factor(n + 1);

    for (int i = 2; i <= n; i ++) {
        if (prime_factor[i] == 0) {
            prime_factor[i] = i;
            if (i <= n / i)
                for (int j = i * i; j <= n; j += i)
                    prime_factor[j] = i;
        }
    }

    int cur = 0;

    dp[1] = 1, dp_acc[1] = 1;

    for (int i = 2; i <= n; i ++) {
        dp[i] = dp_acc[i-1];
        vector<int> factors;
        factors.push_back(1);
        int tmp = i;
        while (tmp > 1) {
            int p = prime_factor[tmp], c = 0, k = factors.size();
            while (tmp % p == 0)
                tmp /= p, c ++;
            for (int j = 0; j < k; j ++) {
                int x = factors[j];
                for (int _ = 0; _ < c; _ ++) {
                    x *= p;
                    factors.push_back(x);
                }
            }
        }
        for (auto &f: factors)
            if (f > 1) {
                cur += dp[i / f] - dp[(i - 1) / f];
                if (cur >= mod) cur -= mod;
                else if (cur < 0) cur += mod;
            }
        dp[i] += cur;
        if (dp[i] >= mod) dp[i] -= mod;
        dp_acc[i] = dp_acc[i-1] + dp[i];
        if (dp_acc[i] >= mod) dp_acc[i] -= mod;
    }
    cout << dp[n];

    return 0;
}