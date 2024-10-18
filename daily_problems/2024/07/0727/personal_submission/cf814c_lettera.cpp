void solve() 
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	map<char,map<int,int>>mp;
	int q;
	cin>>q;
	while(q--)
	{
		int m;
		char c;
		cin>>m>>c;
		int x=mp[c][m];
		if(x){
			cout<<x<<"\n";
		}
		else
		{
			int l=0,r=-1;
			int cnt=0;
			int res=0;
			while(l<n&&r+1<n)
			{
				r++;
				cnt+=s[r]!=c;
				while(cnt>m)
				{
					cnt-=s[l++]!=c;
				}
				res=max(res,r-l+1);
				debug(l,r,cnt,res);
			}
			 
			mp[c][m]=res;
			cout<<res<<"\n";
		}
	}		
}
