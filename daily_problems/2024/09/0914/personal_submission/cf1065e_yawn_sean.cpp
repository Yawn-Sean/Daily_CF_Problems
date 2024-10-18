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

    int n, m, a, mod = 998244353;
    cin >> n >> m >> a;

    int ans = 1, cur = 0;
    while (m --) {
        int num;
        cin >> num;
        int v = quickPow(a, num - cur, mod);
        ans = 1ll * v * (v + 1) / 2 % mod * ans % mod;
        cur = num;
    }

    cout << quickPow(a, n - cur * 2, mod) * ans % mod;

    return 0;
}