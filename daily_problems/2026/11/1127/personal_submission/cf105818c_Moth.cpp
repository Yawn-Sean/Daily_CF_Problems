#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 1e6 + 9;
const int mod = 1e9 + 7;
const int MOD = 998244353;
ll f[N], g[N];
ll ksm(ll a, ll b, ll c)
{
    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return res;
}
void init()
{
    f[0] = g[0] = 1;
    for (int i = 1; i < N; i++)
    {
        f[i] = f[i - 1] * i % MOD;
        g[i] = g[i - 1] * ksm(i, MOD - 2, MOD) % MOD;
    }
}
ll C(ll n, ll m)
{
    if (n < m) return 0;
    if (n < 0 || m < 0) return 0;
    return f[n] * g[m] % MOD * g[n - m] % MOD;
}
void moth()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a < 2 || a + d - b - c != 1) cout << 0 << '\n';
    else cout << C(a + d - 2, d) % MOD * C(b + c, b) % MOD << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    init();
    cin >> _;
    while (_--) moth();
    return 0;
}