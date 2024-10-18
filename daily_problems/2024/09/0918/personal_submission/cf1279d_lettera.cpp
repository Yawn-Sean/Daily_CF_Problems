#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
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
ll inv(ll x)
{
    return qpow(x, mod - 2);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> cnt((int)1e6 + 5);
    vector<vector<int>>a(n+1);
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            cnt[x]++;
            a[i].push_back(x);
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
    	ll cur=inv(n)*inv(a[i].size())%mod*inv(n)%mod;
    	for(int j=0;j<a[i].size();j++)
    	{
    		ans+=cur*cnt[a[i][j]]%mod;
    		ans%=mod;
    	}
    }
    cout<<ans;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    //	cin>>t;
    while (t--)
    {
        solve();
    }
}
