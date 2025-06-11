 #include<bits/stdc++.h>
 using namespace std;
 using ll =long long;
 //#define int ll
 void solve()
 {
 	int n,a,b;
 	cin>>n>>a>>b;
 	ll ans=0;
 	map<ll,ll>cnt1;
 	map<pair<int,int>,int>cnt2;
 	for(int i=0;i<n;i++)
 	{
 		int x,vx,vy;
 		cin>>x>>vx>>vy;
 		ans+=(cnt1[1ll*a*vx-vy]-cnt2[{vx,vy}]);
 		cnt1[1ll*a*vx-vy]++;
 		cnt2[{vx,vy}]++;
 	}
 	cout<<ans*2<<"\n";
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
