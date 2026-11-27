#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 1e6 + 9;
const int mod = 1e9 + 7;
const int MOD = 998244353;
ll f[N], d[N];
void init()
{
    f[0] = 1;
    for (int i = 1; i < N; i++) f[i] = f[i - 1] * i % MOD;
    d[0] = 1;
    for (int i = 2; i < N; i++) d[i] = (d[i - 1] + d[i - 2]) % MOD * (i - 1) % MOD;
}
void moth()
{
    int n;
    cin >> n;
    if (n % 2 == 0) cout << 1 << '\n';
    else cout << f[n] % MOD * d[n] % MOD << '\n';
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