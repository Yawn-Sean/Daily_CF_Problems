#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using i128 = __int128;
using ull = unsigned long long;
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define pqi priority_queue<int> // 优先队列

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long

#define maxn 5007
#define mod 998244353
vector<i64> fac(maxn), invfac(maxn), inv(maxn);

void init()
{
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    invfac[0] = invfac[1] = 1;

    for (int i = 2; i < maxn; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - mod / i * inv[mod % i] % mod;
        invfac[i] = invfac[i - 1] * inv[i] % mod;
    }
}

i64 combi(int n, int k)
{
    if (k > n || k < 0)
        return 0;
    return fac[n] * invfac[k] % mod * invfac[n - k] % mod;
}

i64 f(int x, int y)
{
    i64 ans = 0;
    for (int i = 0; i <= min(x, y); ++i)
    {
        ans += combi(x, i) * combi(y, i) % mod * fac[i] % mod;
        ans %= mod;
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int a, b, c;
    cin >> a >> b >> c;

    i64 res = f(a, b) * f(b, c) % mod * f(a, c) % mod;
    cout << res << endl;
    return 0;
}
