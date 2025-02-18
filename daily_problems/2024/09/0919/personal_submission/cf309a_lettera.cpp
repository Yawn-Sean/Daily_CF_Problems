 #include<bits/stdc++.h>
 using namespace std;
 using ll=long long;
 void solve()
 {
	 ll n,l,t;
	 cin>>n>>l>>t;
	 double ans=0;
	 vector<ll>a(2*n);
	 for(int i=0;i<n;i++)
	 {
	 	cin>>a[i];
	 	a[i+n]=a[i]+l;
	 }
	 ans=1.0*n*(n-1)*(2*t/l);
	 ll d=2*t%l;
	 for(int i=0;i<n;i++)
	 {
	 	int k=upper_bound(a.begin(),a.end(),a[i]+d)-a.begin()-i-1;
	 	ans+=k;
	 }
	 cout<<setprecision(15)<<ans/4<<"\n";
 }
signed main()
 {
 	ios::sync_with_stdio(false),cin.tie(0);
 	int t=1;
  	//cin>>t;
 	while(t--)
 	{
 		solve();
 	}
 }
