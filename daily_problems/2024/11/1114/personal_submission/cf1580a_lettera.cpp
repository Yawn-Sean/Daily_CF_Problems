#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
void solve()
{
	 int n,m;
	 cin>>n>>m;
	 vector<vector<int>>a(n+1,vector<int>(m+1));
	 for(int i=1;i<=n;i++)
	 {
	 	string s;
	 	cin>>s;
	 	for(int j=1;j<=m;j++)
	 	{
	 		a[i][j]=s[j-1]-'0';
	 	}
	 }
	  
	 int ans=n*m;
	 vector<int>pre(m+1);
	 for(int i=1;i<=n-4;i++)
	 {
	 	vector<int>cnt(m+1);
	 	for(int j=i+1;j<i+4;j++)
	 	{
	 		for(int k=1;k<=m;k++)
	 		{
	 			cnt[k]+=a[j][k];
	 		}
	 	}
	 	for(int j=i+4;j<=n;j++)
	 	{
	 		 
	 		//预处理后,左边界往左移动，维护右边界部分的最小贡献
	 		pre=cnt;
	 		for(int k=1;k<=m;k++)
	 		{
	 			pre[k]+=2-a[i][k]-a[j][k];
	 		}
	 		for(int k=1;k<=m;k++)
	 		{
	 			pre[k]+=pre[k-1];
	 		}
	 		int cur=n*m;
	 		for(int k=m;k>=4;k--)
	 		{
	 			cur=min(cur,pre[k-1]+j-i-1-cnt[k]);
	 			ans=min(ans,cur-pre[k-3]+j-i-1-cnt[k-3]);
	 		}
	 		for(int k=1;k<=m;k++)
	 		{
	 			cnt[k]+=a[j][k];
	 		}
	 	}
	 }
	 cout<<ans<<"\n";
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
