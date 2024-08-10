void solve() 
{
	int n,x;
	cin>>n>>x;
	int l=x,r=x;
	ll ans=0;
	while(n--)
	{
		int nl,nr;
		cin>>nl>>nr;
		if(r<nl)
		{
			ans+=nl-r;
			l=r;
			r=nl;
		}
		else if(l>nr)
		{
			ans+=l-nr;
			r=l;
			l=nr;
			 
		}
		else
		{
			l=max(l,nl);
			r=min(r,nr);
		}
	}
	ca;
}
