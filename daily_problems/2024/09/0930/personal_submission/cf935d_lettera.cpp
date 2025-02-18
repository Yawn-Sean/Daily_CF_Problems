#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 #define int ll
const int mod = 1e9 + 7;
ll qpow(ll a, ll b)
{
    a %= mod;
    ll ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
ll inv(ll x)
{
    return qpow(x, mod - 2);
}
ll MOD(ll x)
{
    return (x % mod + mod) % mod;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    ll ans = 0, pre = 1;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<ll> f(m + 1);
    for (int i = 1; i <= m; i++)
    {
        f[i] = (f[i - 1] + i) % mod;
    }
    for (int i = 0; i < n; i++)
    {
        ll add = 0,tmp=pre;
        if (!a[i])
        {
            if (!b[i])
            {
                add = f[m - 1] * inv(m * m) % mod;
               
            }
            else
            {
                add = (m - b[i]) * inv(m) % mod;
            }
              tmp=tmp*inv(m)%mod;
        }
        else
        {
            if (!b[i])
            {
            	
                add = (a[i] - 1) * inv(m) % mod;
                tmp=tmp*inv(m)%mod;
            }
            else
            {
                if (a[i] != b[i])
                {
                	if(a[i]>b[i])
                	{
                		ans=(ans+pre)%mod;
                	}
                    break;
                }
            }
        }
        ans = MOD(ans + pre *add%mod);
        pre=tmp;
    }
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
