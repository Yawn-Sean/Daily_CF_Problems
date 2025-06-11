 #include<bits/stdc++.h>
 using namespace std;
 using ll =long long;
 //#define int ll
 const int M=2e5+5;
 void solve()
 {
 	int n;
 	cin>>n;
 	vector<ll>pre(M),a(n),res(M);
 	for(int i=0;i<n;i++)
 	{
 		int x;
 		cin>>x;
 		a[i]=x;
 		pre[x]++;
 	}
 	for(int i=1;i<M;i++)
 	{
 		pre[i]+=pre[i-1];
 	}
 	for(int i=1;i<M;i++)
 	{
 		for(int j=0;j<M;j+=i)
 		{
 			res[i]+=(pre[min(M-1,j+i-1)]-(j>0?pre[j-1]:0))*j;
 		}
 	}
 	ll ans=0;
 	for(auto x:a)
 	{
 		ans=max(ans,res[x]);
 	}
 	cout<<ans<<"\n";
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
