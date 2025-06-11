void solve()
{
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	s--,t--;
	fo(i,0,m)
	{
		int u,v;
		cin>>u>>v;
		u--,v--;
		e[u].eb(v);
		e[v].eb(u);
	}
	 
	dijkstra(s,d1);
	dijkstra(t,d2);
	int ans=0-m;
	int tg=d1[t];
	//debug(tg);
	 
	fo(i,0,n)
	{
		fo(j,i+1,n)
		{
				if(min(d1[i]+d2[j],d1[j]+d2[i])+1>=tg)
				{
					//debug(d1[i]+d2[j]);
					ans++;
					
				}
			
				 
		}
	
	}
	ca;
}
