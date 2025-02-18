void solve() 
{
	ll n,m;
	cin>>n>>m;
	vc<int>a(n+1);
	int l=1,r=n;
	ll sum=pow(2,n-1);
	int cnt=1;
	while(l<=r)
	{
		if(m<=sum/2)
		{
			a[l++]=cnt++;
		}
		else
		{
			m-=sum/2;
			a[r--]=cnt++;
		}
		sum/=2;
	}
	fo(i,1,n+1)
	{
		cout<<a[i]<<" \n"[i==n];
	}
}
