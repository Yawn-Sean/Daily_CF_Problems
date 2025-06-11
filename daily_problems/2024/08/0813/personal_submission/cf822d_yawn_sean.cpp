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

    vector<int> prime_factor(5e6 + 1), dp(5e6 + 1);
    int mod = 1e9 + 7;

    iota(prime_factor.begin(), prime_factor.end(), 0);

    for (int i = 2; i <= 3e3; i ++) {
        if (prime_factor[i] == i) {
            for (int j = i * i; j <= 5e6; j += i) {
                if (prime_factor[j] == j) {
                    prime_factor[j] = i;
                }
            }
        }
    }

    for (int i = 2; i <= 5e6; i ++) {
        dp[i] = (dp[i / prime_factor[i]] + 1ll * i * (prime_factor[i] - 1) / 2 % mod) % mod;
    }

    int t, l, r;
    cin >> t >> l >> r;

    long long ans = 0;
    for (int i = r; i >= l; i --) {
        ans = (ans * t + dp[i]) % mod;
    }
    cout << ans;

    return 0;
}