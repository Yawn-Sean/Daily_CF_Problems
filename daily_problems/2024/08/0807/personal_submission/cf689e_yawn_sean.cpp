#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

long long pow(long long x, long long y, long long mod) {
    if (y == 0) return 1;
    if (y == 1) return x % mod;
    long long ans = pow(x, y / 2, mod);
    ans = ans * ans % mod;
    if (y % 2) ans = ans * x % mod;
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, mod = 1e9 + 7;
    cin >> n >> k;

    vector<long long> f(n + 1, 1), g(n + 1, 1);
    for (int i = 1; i <= n; i ++)
        f[i] = f[i-1] * i % mod;
    
    g[n] = pow(f[n], mod - 2, mod);

    for (int i = n; i > 0; i --)
        g[i-1] = g[i] * i % mod;

    map<int, int> diff;
    for (int i = 0; i < n; i ++) {
        int l, r;
        cin >> l >> r;
        diff[l] ++;
        diff[r+1] --;
    }

    int last_key = 0, cur = 0;
    int ans = 0;
    for (auto &[key, value]: diff) {
        if (cur >= k) {
            ans += 1ll * (key - last_key) * f[cur] % mod * g[k] % mod * g[cur - k] % mod;
            if (ans >= mod) ans -= mod;
        }
        last_key = key;
        cur += value;
    }
    cout << ans;

    return 0;
}