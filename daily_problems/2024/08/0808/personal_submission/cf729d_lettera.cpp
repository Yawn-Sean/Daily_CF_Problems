void solve() 
{
	int m,n,len,num;
	cin>>m>>n>>len>>num;
	string s;
	cin>>s;
	vc<int>a;
	int cur=0;
	fo(i,0,m)
	{
		if(s[i]=='1')
		{
			cur=0;
		}
		else
		{
			cur++;
			if(cur==len)
			{
				a.pb(i+1);
				cur=0;
			}
		}
	}
	fo(i,0,n-1)
	{
		
		assert(len(a)!=0);
		a.pop_back();
	}
	cout<<len(a)<<"\n";
	for(auto x:a)
	{
		cout<<x<<" ";
	}
	cn;
}
