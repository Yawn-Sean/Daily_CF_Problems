void solve() 
{
	sieve();
	int t,l,r;
	cin>>t>>l>>r;
	//dp[x]=dp[x/y]+x*(y-1)/2,y is min prime divisor
	vc<ll>dp(r+1);
	fo(i,2,r+1)
	{
		int y=v[i];
		dp[i]=dp[i/y]+1ll*i*(y-1)/2;
		dp[i]%=mod;
	}
	ll res=1;
	ll ans=0;
	fo(i,l,r+1)
	{
		res=i>l?res*t:res;
		res%=mod;
		ans=(ans+res*dp[i])%mod;
	}
	ca;
}
