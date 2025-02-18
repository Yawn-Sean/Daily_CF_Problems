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

    int n, mod = 998244353;
    cin >> n;

    int M = 1e6;

    vector<int> f(M + 1, 1), g(M + 1, 1);

    for (int i = 1; i <= M; i ++)
        f[i] = 1ll * f[i-1] * i % mod;
    
    g[M] = quickPow(f[M], mod - 2, mod);

    for (int i = M; i >= 1; i --)
        g[i-1] = 1ll * g[i] * i % mod;
    
    auto inv = [&] (int x) -> int {
        return 1ll * f[x-1] * g[x] % mod;
    };

    vector<int> cnt(1e6 + 1, 0);
    vector<vector<int>> pools;

    for (int i = 0; i < n; i ++) {
        int k;
        cin >> k;
        vector<int> pool(k);
        for (auto &x: pool)
            cin >> x, cnt[x] ++;
        pools.emplace_back(pool);
    }

    int ans = 0;
    for (int i = 0; i < n; i ++) {
        int k = pools[i].size();
        for (auto &v: pools[i]) {
            ans += 1ll * cnt[v] * inv(k) % mod;
            if (ans >= mod) ans -= mod;
        }
    }
    cout << 1ll * ans * inv(n) % mod * inv(n) % mod;

    return 0;
}