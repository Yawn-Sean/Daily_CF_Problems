#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353, mx = 2e5 + 5;
// #define int ll
ll fac[mx], invfac[mx], f[mx];
ll qpow(ll a, ll b)
{
    a %= mod;
    ll ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ret;
}
void ins(int x, int v)
{
    for (int i = x; i < mx; i += (i & -i))
    {
        f[i] = (f[i] + v) % mod;
    }
}
ll ask(int x)
{
    ll ret = 0;
    for (int i = x; i; i -= (i & -i))
    {
        if (f[i] > 0)
            ret = (ret + f[i]) % mod;
    }
    return ret;
}
void solve()
{
    fac[0] = 1;
    for (int i = 1; i < mx; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    invfac[mx - 1] = qpow(fac[mx - 1], mod - 2);
    for (int i = mx - 2; i >= 0; i--)
    {
        invfac[i] = invfac[i + 1] * (i + 1) % mod;
    }
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    vector<int> a(n), b(m), cnt(mx), cnt2(mx);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll cur=fac[n];
    for (int i = 0; i < mx; i++)
    {
        if (cnt[i])
        {
            ins(i, cnt[i]);
            cur=cur*invfac[cnt[i]]%mod;
        }
         
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        
    }

	for(int i=0;i<m;i++)
	{
		if(i>=n)
		{
			ans=(ans+1)%mod;
			break;
		}
		int t=ask(b[i]-1);
		cur=cur*fac[n-i-1]%mod*invfac[n-i]%mod;
		ans=(ans+t*cur%mod)%mod;
		cur=cur*cnt[b[i]]%mod;
		ins(b[i],-1);
		cnt[b[i]]--;
		if(cnt[b[i]]<0)break;
	}
    cout << ans << "\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}
