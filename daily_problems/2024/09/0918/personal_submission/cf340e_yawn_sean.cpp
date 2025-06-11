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

    int n, mod = 1e9 + 7;
    cin >> n;

    vector<int> f(n + 1, 1), g(n + 1, 1);

    for (int i = 1; i <= n; i ++)
        f[i] = 1ll * f[i-1] * i % mod;
    
    g[n] = quickPow(f[n], mod - 2, mod);

    for (int i = n; i >= 1; i --)
        g[i-1] = 1ll * g[i] * i % mod;
    
    auto inv = [&] (int x) -> int {
        return 1ll * f[x-1] * g[x] % mod;
    };

    vector<int> perm(n), used(n, 0);
    for (int i = 0; i < n; i ++) {
        cin >> perm[i], perm[i] --;
        if (perm[i] >= 0)
            used[perm[i]] = 1;
    }

    int x0 = 0, x1 = 0;
    for (int i = 0; i < n; i ++) {
        if (!used[i]) {
            if (perm[i] >= 0) x1 ++;
            else x0 ++;
        }
    }

    int ans = 0, cur = 1;
    for (int i = 0; i <= x0; i ++) {
        ans += 1ll * cur * f[x0 + x1 - i] % mod * f[x0] % mod * g[i] % mod * g[x0 - i] % mod;
        cur = -cur;
        if (ans >= mod) ans -= mod;
        if (ans < 0) ans += mod;
    }
    cout << ans;

    return 0;
}