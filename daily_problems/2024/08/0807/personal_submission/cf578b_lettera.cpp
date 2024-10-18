void solve() 
{
	int n,k,x;
	cin>>n>>k>>x;
	vc<ll>a(n+1),p(n+1),s(n+2);
	fo(i,1,n+1)
	{
		cin>>a[i];
		p[i]=a[i]|p[i-1];
		s[i]=a[i];
	}
	rfo(i,n-1,1)
	{
		s[i]|=s[i+1];
	}

	ll mul=pow(x,k);
	ll ans=0;
	fo(i,1,n+1)
	{
		ll res=p[i-1]|s[i+1]|(mul*a[i]);
		ans=max(ans,res);
	}
	ca;
}
