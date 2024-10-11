void solve() 
{
	ll d,m;
	cin>>d>>m;
	int cur=1;
	ll ans=1;
	while(cur<=d)
	{
		ans=ans*(min<int>(cur,d-cur+1)+1)%m;
		cur<<=1;
	}
	ans=(ans-1+m)%m;
	ca;
}
