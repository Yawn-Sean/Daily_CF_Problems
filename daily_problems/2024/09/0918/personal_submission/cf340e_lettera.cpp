#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
ll qpow(ll a, ll b)
{
    a %= mod;
    ll ret=1;
    while (b)    
    {
    	if(b&1)ret=ret*a%mod;
    	b>>=1;
    	a=a*a%mod;
    }
    return ret;
}
void solve()
{
    int n;
    cin >> n;
    int x0 = 0, x1 = 0;
    vector<ll> cnt(n + 1), a(n), A(n + 1, 1), inv(n + 1,1);
    for (int i = 1; i <= n; i++)
    {
        A[i] = A[i - 1] * i % mod;
        inv[i]=qpow(A[i],mod-2);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
        if(x>-1)
        cnt[x]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
        {
            if (!cnt[i + 1])
                x0++;
            else
                x1++;
        }
    }
    ll ans=0,f=1;
    for(int i=0;i<=x0;i++)
    {
    	ans+=f*A[x0]*inv[x0-i]%mod*inv[i]%mod*A[x0+x1-i]%mod;
    	ans=(ans+mod)%mod;
    	f*=-1;
    }
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}
