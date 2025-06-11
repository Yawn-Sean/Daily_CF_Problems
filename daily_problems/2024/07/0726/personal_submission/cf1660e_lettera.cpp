void solve() 
{
	int n;
	cin>>n;
	vv(int,a,n+1,n+1);
	int cnt=0;
	fo(i,1,n+1)
	{
		string s;
		cin>>s;
		fo(j,1,n+1)
		{
			a[i][j]=s[j-1]=='1';
			cnt+=a[i][j];
		}
	}
	int ans=n*n;
	fo(i,1,n+1)
	{
		int cnt1=0;
		fo(j,0,n)
		{
			cnt1+=a[(i-1+j)%n+1][j%n+1];
			debug((i-1+j)%n+1,j%n+1);
		}
		int res=n-cnt1+cnt-cnt1;
		debug(res,ans);
		ans=min(ans,res);
	}
	ca;
}
