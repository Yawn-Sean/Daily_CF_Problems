void solve() 
{
	int a,b;
	cin>>a>>b;
	__int128 sum=0;
	__int128 res=1ll*b*(b-1)/2;
	fo(k,1,a+1)
	{
		 
		sum=(sum+(b*k+1)*res)%mod ;
	}
	print(sum);
}
