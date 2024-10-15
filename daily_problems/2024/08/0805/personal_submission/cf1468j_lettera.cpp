void solve() 
{
	 init();
	cin>>n>>m>>k;
	fo(i,0,m)
	{
		int u,v,w;
		cin>>u>>v>>w;
		u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	prim(0);
	if(mx<k)
	{
		ans=d;
	}
	ca;
}
