void solve() 
{
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int l=0,r=n-1;
	while(l+1<n&&a[l+1]>a[l])
	{
		l++;
	}
	while(r-1>=0&&a[r-1]>a[r])
	{
		r--;
	}
	int c=((l+1)%2==1)+((n-r)%2==1);
	int f=1;
	if(c==0)f=0;
	if(f)cout<<"Alice\n";
	else cout<<"Bob\n";
}
