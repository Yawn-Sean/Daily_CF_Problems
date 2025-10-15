#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
void solve()
{
	 int n;
	 cin>>n;
	 vector<int>a(n+1);
	 map<int,int>cnt;
	 vector<int>c;
	 int ans1=1,ans2=1e4;
	 int f=0;
	 for(int i=1;i<=n;i++)
	 {
	 	cin>>a[i];
	 	cnt[a[i]]++;
	 	if(cnt[a[i]]==4)
	 	{
	 		f=1;
	 		ans1=a[i];
	 	}
	 }
	 if(f)
	 {
	 	 for(int i=0;i<4;i++)
	 	 {
	 	 	cout<<ans1<<" \n"[i==3];
	 	 }
	 	 return;
	 }
	 for(auto [x,y]:cnt)
	 {
	 	for(int i=0;i<y/2;i++)
	 	{
	 		c.push_back(x);
	 	}
	 }
	 for(int i=0;i<(int)c.size()-1;i++)
	 {
	 	if(c[i+1]*ans1<c[i]*ans2)
	 	{
	 		ans1=c[i];
	 		ans2=c[i+1];
	 	}
	 }
	 for(int i=0;i<2;i++)
	 {
	 	cout<<ans1<<" "<<ans2<<" \n"[i==1];
	 }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
