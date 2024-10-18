 #include<bits/stdc++.h>
 using namespace std;
 using ll=long long;
 void solve()
 {
	 ll x,y,n;
	 cin>>x>>y>>n;
	 ll ansa,ansb,res1=1e9,res2=1;
	 for(ll b=1;b<=n;b++)
	 {
	 	ll a=b*x/y;
		for(ll i=a-1;i<=a+1;i++)
		{
			if(abs(i*y-b*x)*res2<res1*b*y)
			{
				res1=abs(i*y-b*x);
				res2=b*y;
				ansa=i;
				ansb=b;
			}
		}
	 }
	 cout<<ansa<<"/"<<ansb<<"\n";
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
