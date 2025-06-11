#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
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

    int mod = 998244353;
    int M = 4e5;
    vector<int> facs(M + 1, 1), fac_invs(M + 1, 1);

    for (int i = 1; i <= M; i ++) {
        facs[i] = 1ll * facs[i - 1] * i % mod;
    }

    fac_invs[M] = quickPow(facs[M], mod - 2, mod);
    for (int i = M; i >= 1; i --) {
        fac_invs[i - 1] = 1ll * fac_invs[i] * i % mod;
    }

    auto c = [&] (int x, int y) -> int {
        if (y < 0 || y > x) return 0;
        return 1ll * facs[x] * fac_invs[x - y] % mod * fac_invs[y] % mod;
    };

    int h, w;
    cin >> h >> w;

    int ans = 0;
    // 一种颜色
    ans += 3;

    // 两种颜色
    ans += 2 * (c(h + w, h) - 2) % mod;
    if (ans >= mod) ans -= mod;

    cout << ans << '\n';

    return 0;
}