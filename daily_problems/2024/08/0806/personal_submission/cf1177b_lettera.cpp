void solve() 
{
	ll k;
	cin>>k;
	ll x=9;
	ll base=1;
	int cnt=1;
	while(k>x*cnt)
	{
		k-=x*cnt;
		x*=10;
		base*=10;
		cnt++;
	}
	ll num=base+(k-1)/cnt;
	int ans=0;
	k=(k-1)%cnt+1;
	num/=qpow(10,cnt-k);
	ans=num%10;
	ca;
}
