#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
void solve()
{
	 int n;
	 cin>>n;
	 vector<int>a(n+1);
	 for(int i=1;i<=n;i++)
	 {
	 	cin>>a[i];
	 }
	 reverse(a.begin()+1,a.end());
	 string s;
	 cin>>s;
	 s=" "+s;
	 reverse(s.begin()+1,s.end());
	 vector<int>suf(n+2);
	 for(int i=n;i>=1;i--)
	 {
	 	suf[i]=suf[i+1]+a[i];
	 }
	 vector<int>pre(n+1);
	 for(int i=1;i<=n;i++)
	 {
	 	pre[i]=pre[i-1];
	 	if(s[i]=='1')
	 	{
	 		pre[i]+=a[i];
	 	}
	 }
	 int ans=pre[n];
	 for(int i=1;i<=n;i++)
	 {
	 	if(s[i]=='1')
	 	{
	 		ans=max(ans,pre[i-1]+suf[i+1]);
	 	}
	 }
	 cout<<ans;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
