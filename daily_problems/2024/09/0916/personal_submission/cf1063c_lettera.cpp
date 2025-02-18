 #include<bits/stdc++.h>
 using namespace std;
 using ll=long long;
 int ask(int x,int y)
 {
 	cout<<x<<" "<<y<<endl;
 	string s;
 	cin>>s;
 	return s[0]=='b';
 }
 void solve()
 {
	int n;
	cin>>n;
	int l=0,r=1e9;
	int col=ask(r,r);
	for(int i=0;i<n-1;i++)
	{
		int mid=(l+r)/2;
		if(col!=ask(mid,mid))
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	cout<<l<<" "<<r<<" "<<r<<" "<<l<<endl;
 }
 int main()
 {
 	ios::sync_with_stdio(false),cin.tie(0);
 	int t=1;
  	//cin>>t;
 	while(t--)
 	{
 		solve();
 	}
 }
