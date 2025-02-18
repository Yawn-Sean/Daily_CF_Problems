#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

long long quickPow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = quickPow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}




signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, g;
    cin >> n >> m >> g;

    int mod = 1e9 + 7;
    vector<int> f(n + m + 1, 1), rev(n + m + 1, 1);
    for (int i = 1; i <= n + m; i ++)
        f[i] = 1ll * f[i - 1] * i % mod;
    rev[n + m] = quickPow(f[n + m], mod - 2, mod);
    for (int i = n + m; i >= 1; i --)
        rev[i - 1] = 1ll * rev[i] * i % mod;

    if (!m) {
        int cur = 0;
        for (int i = 0; i < n - 1; i ++)
            cur = 1 - cur;
        cout << (cur == g ? 1 : 0);
    }
    else if (m == 1) {
        int ans = 0, cur = 0;
        for (int i = 0; i < n; i ++) {
            if (cur == g) ans ++;
            cur = 1 - cur;
        }
        cout << ans + (cur ^ g);
    }
    else {
        int ans = 0, cur = 0;
        for (int c0 = 0; c0 <= n; c0 ++) {
            if (cur == g) {
                ans += 1ll * f[n + m - 1 - c0] * rev[n - c0] % mod * rev[m - 1] % mod;
                if (ans >= mod) ans -= mod;
            }
            cur = 1 - cur;
        }
        cout << ans;
    }

    return 0;
}