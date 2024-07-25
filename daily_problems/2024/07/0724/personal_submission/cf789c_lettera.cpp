void solve() 
{
	int n;
	cin>>n;
	vc<int>a(n);
	fo(i,0,n)
	{
	cin>>a[i];
	}
	int g=0;
	fo(i,0,n)
	{
		g=gcd(g,a[i]);
	}
	int ans=0;
	if(g==1)
	{
		int cnt=0;
		fo(i,0,n)
		{
			if(a[i]&1)
			{
				cnt++;
			}
			else
			{
				ans+=cnt/2+cnt%2*2;
				cnt=0;
			}
		}
		ans+=cnt/2+cnt%2*2;
	}
	CY;
	ca;
}
