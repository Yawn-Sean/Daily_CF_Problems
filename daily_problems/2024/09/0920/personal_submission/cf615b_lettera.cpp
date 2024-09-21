#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> dp(n,1), vis(n),d(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if(u>v)swap(u,v);
        g[u].push_back(v);
        d[u]++;
        d[v]++;
    }
  	for(int i=0;i<n;i++)
  	{
  		for(auto v:g[i])
  		{
  			dp[v]=max(dp[v],dp[i]+1);
  		}
  	}
    ll ans=0;
    for(int i=0;i<n;i++)
    {
    	//cerr<<i<<" "<<dp[i]<<endl;
    	ans=max<ll>(ans,1ll*dp[i]*d[i]);
    }
    cout<<ans<<endl;
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
