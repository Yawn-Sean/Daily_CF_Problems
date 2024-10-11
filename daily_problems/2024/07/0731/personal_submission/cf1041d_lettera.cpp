void solve() 
{
	int n,h;
	cin>>n>>h;
	vc<int>ls(n),rs(n);
	fo(i,0,n)
	{
		cin>>ls[i]>>rs[i];
		
	}
	
	int l=0,r=0,cur=h,res=0;//current height
	int ans=0;
	while(l<n)
	{
		while(r<n-1&&ls[r+1]-rs[r]<cur)
		{
			res+=rs[r]-ls[r];
			cur-=ls[r+1]-rs[r];
			r++;
		}
		ans=max(ans,res+h+rs[r]-ls[r]);
		res-=rs[l]-ls[l];
		if(l<n-1)
		{
			cur+=ls[l+1]-rs[l];
		}
		 
		l++;
	}
	ca;
}
