void solve() 
{
	int q;
	cin>>n>>q;
	init();
	while(q--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		a--,b--,c--;
		int x=dis(a,b);
		int y=dis(a,c);
		int z=dis(b,c);
		int mm=min({x,y,z});
		int ans=(x+y+z)/2-mm+1;
		ca;
	}
}
