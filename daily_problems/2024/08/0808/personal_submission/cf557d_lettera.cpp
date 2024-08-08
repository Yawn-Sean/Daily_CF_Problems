void solve() 
{
	int n,m;
	cin>>n>>m;
	fo(i,0,m)
	{
		int u,v;
		cin>>u>>v;
		u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll ans=0;
	if(m==0)
	{
		ans=1ll*n*(n-1)*(n-2)/6;
		cout<<3<<" "<<ans<<"\n";	
	}
	else
	{
		
		fo(i,0,n)
		{
			 
			if(col[i]==-1)
			{
				c1=0,c2=0;
				col[i]=1;
			   bool flag=dfs(i);
			   if(flag)
			  {
				cout<<0<<" "<<1<<"\n";
				return;
			  }
			  debug(c1,c2);
			  ans+=C(c1,2)+C(c2,2);
			}
			 
		}
		if(ans)
		{
			cout<<1<<" "<<ans<<"\n";
		}
		else
		{
			cout<<2<<" "<<1ll*m*(n-2)<<"\n";
		}
	}
}
