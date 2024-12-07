#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void chmin(int &a,int b)
{
	a=min(a,b);
}
void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int>p(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	if(n==1)
	{
		cout<<1<<"\n";
		return;
	}
	int ans=0;
	vector<vector<int>>dp(n+2,vector<int>(n+3,k+1));
	vector<int>f(n+2);
	for(int i=n;i>=1;i--)
	{
		f[i]=max(f[i+1],p[i]);
	}
	dp[1][2]=0;
	//(i,j)->(i,j+1),p[i]!=0&&j后面的数没有100
	//(i,j)->(i+1,j),j后面有非0的数,且p[i]非100
	//(i,j)->(j+1,j+2),p[i]非0,j后面有非0的数
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(dp[i][j]>k)
			{
				continue;
			}
			if(p[i]&&f[j]<100)
			{
				chmin(dp[i][j+1],dp[i][j]+1);
			}
			if(p[i]<100&&f[j])
			{
				chmin(dp[j][j+1],dp[i][j]+1);
			}
			if(p[i]&&f[j])
			{
				chmin(dp[j+1][j+2],dp[i][j]+1);
			}
		}
	}
	for(int i=1;i<=n+1;i++)
	{
		for(int j=i+1;j<=n+2;j++)
		{
			ans+=dp[i][j]<=k;
			//cerr<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
   // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
