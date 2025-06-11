#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
const int inf=1E9+10;
void solve()
{
	 int n,m;
	 cin>>n>>m;
	 //long long
	 vector<int>a(n+1);
	 vector<vector<array<int,3>>>c(n+1);
	 vector<int>ans;
	 for(int i=1;i<=n;i++)
	 {
	 	cin>>a[i];
	 }
	 for(int i=1;i<=m;i++)
	 {
	 	int e,t,p;
	 	cin>>e>>t>>p;
	 	c[e].push_back({t,p,i});
	 }
	 int f=1;
	 int time=0;
	 for(int i=1;i<=n;i++)
	 {
	 	int nn=c[i].size();
	 	vector<int>dp(101,inf);
	 	vector<vector<int>>jump(nn+1,vector<int>(101,-1));
	 	dp[0]=0;
	 	for(int j=0;j<nn;j++)
	 	{
	 		auto [t,p,id]=c[i][j];
	 		for(int k=100;k>=0;k--)
	 		{
	 			int cur=min(100,k+p);
	 			if(dp[k]+t<=a[i]&&dp[cur]>dp[k]+t)
	 			{
	 				dp[cur]=dp[k]+t;
	 				jump[j+1][cur]=k+id*101;
	 			}
	 		}
	 	}
		if(dp[100]>a[i]-time)
		{
			f=0;
			break;
		}
		else
		{
			time+=dp[100];
		}
		int now=100;
		for(int j=nn;j;j--)
		{
			if(~jump[j][now])
			{
				ans.push_back(jump[j][now]/101);
				now=jump[j][now]%101;
			}
		}
	 }
	 if(f)
	 {
	 	cout<<ans.size()<<"\n";
	 	for(auto x:ans)
	 	{
	 		cout<<x<<" ";
	 	}
	 	cout<<"\n";
	 }
	 else
	 {
		cout<<-1<<"\n";
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
