#include <bits/stdc++.h>
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

    int n, m, k, r, c, mod = 1e9+7;
    cin >> n >> m >> k >> r >> c;

    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    cout << quickPow(k, 1ll * n * m - ((ax == bx) && (ay == by) ? 0 : 1ll * r * c), mod) << '\n';

    return 0;
}