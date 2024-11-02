#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
const int mod=1e9+7;
ll qpow(ll a,ll b)
{
	a%=mod;
	ll ret=1;
	while(b)
	{
		if(b&1)ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll x)
{
	return qpow(x,mod-2);
}
ll MOD(ll x)
{
	return (x%mod+mod)%mod;
}
void solve()
{
       int n,k;
       cin>>n>>k;
       k++;
       if(k==1)
       {
       	cout<<MOD(n*2);
       	return;
       }
       if(n==0)
       {
       	cout<<0;
       	return;
       }
       int ans=MOD(n%mod*qpow(2,k)%mod-MOD((qpow(2,k)-1)*inv(2))+inv(2));
       cout<<ans;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
