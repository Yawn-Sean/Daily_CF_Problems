#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
void solve()
{
	 ll ans=0;
	 int n,x,y;
	 cin>>n>>x>>y;
	 vector<vector<int>>g(n+1);
	 for(int i=1;i<n;i++)
	 {
	 	int u,v;
	 	cin>>u>>v;
	 	g[u].push_back(v);
	 	g[v].push_back(u);
	 }
	 vector<int>vis(n+1),sz(n+1,1);
	 int cnt=1;
	 auto dfs=[&](auto self,int u,int fa)->void
	 {
	 	for(auto v:g[u])
	 	{
	 		if(v!=fa)
	 		{	
	 			self(self,v,u);
	 			sz[u]+=sz[v];
	 			vis[u]=max(vis[u],vis[v]);
	 			if(u==x&&!vis[v])
	 			{
	 				cnt+=sz[v];
	 			}
	 		}
	 	}
	 	if(u==y)
	 	{
	 		vis[u]=1;
	 	}
	 };
	 dfs(dfs,x,0);
	 ans=1ll*cnt*(n-sz[y]-1)+1ll*(n-cnt)*(n-1);
	 cout<<ans;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
   // cin >> t;
    while (t--)
    {
        solve();
    }
}
