#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int>deg(n+1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin>>x;
        if(x)
        {
        	deg[i]^=1;
        	deg[x]^=1;
        	g[i].push_back(x);
        	g[x].push_back(i);
        }
    }
    if(n%2)
    {
    	cout<<"YES\n";
    }
    else
    {
    	cout<<"NO\n";
    	return;
    }
    vector<int>vis(n+1);
    auto dfs1=[&](auto self,int u,int fa)->void
    {
    	cout<<u<<"\n";
    	vis[u]++;
    	for(auto v:g[u])
    	{
    		if(!vis[v]&&v!=fa)
    		{
    			self(self,v,u);
    		}
    		 
    	}
    };
    auto dfs2=[&](auto self,int u,int fa)->void
    {
    	for(auto v:g[u])
    	{
    		if(v!=fa)
    		{
    			self(self,v,u);
    		}
    		 
    	}
    	if(!deg[u])
    	{
    	     deg[fa]^=1;
    	     dfs1(dfs1,u,fa);
    	}
    };
    dfs2(dfs2,1,0);
    
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
