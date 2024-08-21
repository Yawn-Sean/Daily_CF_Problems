void solve() 
{
	//找应该保留的点，在dfs过程找保留该点应该保留的边
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<tp>>g(n);
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		u--,v--;
		g[u].push_back({v,w,i});
		g[v].push_back({u,w,i});
	}
	vector<int>dis(n,1e15);
	dis[0]=0;
	priority_queue<PII,vector<PII>,greater<PII>>q;
	q.push({0,0});
	vector<int>p(n,-1);
	while(!q.empty())
	{
		auto [d,u]=q.top();
		q.pop();
		if(dis[u]==d)
		{
			for(auto [v,w,i]:g[u])
			{
				if(dis[v]>w+dis[u])
				{
					dis[v]=w+dis[u];
					p[v]=i;
					q.push({dis[v],v});
				}
			}
		}
	}
	vector<int>order(n-1);
	iota(order.begin(),order.end(),1);
	sort(order.begin(),order.end(),[&](int i,int j)
	{
		return dis[i]<dis[j];
	});
	int ans=min(n-1,k);
	cout<<ans<<"\n";
	for(int i=0;i<ans;i++)
	{
		cout<<p[order[i]]+1<<" ";
	}
	cout<<"\n";
}
