#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
//const int mod = 1 ? 998244353 : 1e9 + 7;
//#define int ll
void solve() 
{
	
	//最小化最大值考虑二分
	//n不大，考虑dp 允许O(n^2)
	//最少不改变n-k个元素
	//dp[i]:第i个数不变时，前i个数不变的数的最大个数
	//dp[i]=max(dp[j]+1,dp[i]),abs(a[i]-a[j])<=m*(i-j)
	int l=0,r=2e9;
	int n,k;
	cin>>n>>k;
	vector<int>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	vector<int>dp(n,1);
	while(l<r)
	{
		int m=l+(r-l)/2;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(abs(a[i]-a[j])<=1ll*m*(i-j))
				{
					dp[i]=max(dp[j]+1,dp[i]);
				}
			}
		}
		int mx=*max_element(begin(dp),end(dp));
		if(mx>=n-k)
		{
			r=m;
		}
		else
		{
			l=m+1;
		}
		fill(dp.begin(),dp.end(),1);
	}
	cout<<l<<endl;
}
signed main() {
  ios::sync_with_stdio(false),cin.tie(0);
  int t;
  t = 1;
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  //cin >> t;
  while (t--) {
    solve();
  }
}









