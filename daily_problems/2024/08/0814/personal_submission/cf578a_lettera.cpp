void solve() 
{
	int  a,b;
	cin>>a>>b;
	if(a<b)
	{
		cout<<-1<<endl;
		return;
	}
	double ans=1e9+1;
	if(a==b)
	{
		ans=a;
	}
	int x=floor(1.0*(a-b)/b);
	if(x&1) x--;
	if(!x) x=-1;
	 double res=1.0*(a-b)/x<=0?1e9+1:1.0*(a-b)/x;
	 ans=min(ans,res);
	x=floor(1.0*(a+b)/b);
	if(x&1) x--;
	if(!x) x=-1;
	res=min(ans,1.0*(a+b)/x<=0?1e9+1:1.0*(a+b)/x);	
	 ans=min(ans,res);
	if(ans==1e9+1) ans=-1;
	cout<<setprecision(15)<<ans<<endl;
}
