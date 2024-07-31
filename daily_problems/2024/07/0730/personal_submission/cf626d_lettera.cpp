void solve() 
{
	int n;
	cin>>n;
	vc<int>a(n),cnt1(5000);
	vc<ll>cnt2(5000);
	fo(i,0,n)
	{
		cin>>a[i];
	}
	fo(i,0,n)
	{
		fo(j,0,i)
		{
			cnt1[abs(a[i]-a[j])]++;
		
		}
	}
	fo(i,0,5000)
	{
		fo(j,0,5000-i)
		{
			cnt2[i+j]+=cnt1[i]*cnt1[j];
		}
	}
	fo(i,0,4999)
	{
		cnt2[i+1]+=cnt2[i];
	}
	ll res=0;
	fo(i,1,5000)
	{
		res+=1ll*cnt2[i-1]*cnt1[i];
	}
	
	double sum=pow(1ll*n*(n-1)/2,3);
	double ans=1.0*res/sum;
	cout<<setprecision(15)<<ans<<"\n";
	
}
