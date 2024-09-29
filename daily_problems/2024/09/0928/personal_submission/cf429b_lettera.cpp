#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>>a(n+2,vector<int>(m+2));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++){cin>>a[i][j];}
	}
	vector<vector<int>>dp1(n+2,vector<int>(m+2));
	vector<vector<int>>dp2(n+2,vector<int>(m+2));
	vector<vector<int>>dp3(n+2,vector<int>(m+2));
	vector<vector<int>>dp4(n+2,vector<int>(m+2));
	//枚举相遇点,更新ans
	//dp1表示从(1,1)到(i,j)的最大gain,inclusive 
	//dp2表示从(n,m)到(i,j)的最大gain
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1])+a[i][j];
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=m;j>=1;j--)
		{
			dp2[i][j]=max(dp2[i+1][j],dp2[i][j+1])+a[i][j];
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=m;j++)
		{
			dp3[i][j]=max(dp3[i+1][j],dp3[i][j-1])+a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			dp4[i][j]=max(dp4[i-1][j],dp4[i][j+1])+a[i][j];
		}
	}
	int ans=0;
	for(int i=2;i<n;i++)
	{
		for(int j=2;j<m;j++)
		{
			 ans = max(ans, dp1[i - 1][j] + dp2[i+1][j] + dp3[i][j - 1] + dp4[i][j+1]);
           ans = max(ans, dp3[i +1][j] + dp4[i-1][j] + dp1[i][j - 1] + dp2[i][j+1]);
		}
	}
	cout<<ans<<"\n";
}	 
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
