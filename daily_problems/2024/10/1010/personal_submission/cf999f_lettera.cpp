#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
const int M = 1E5 + 5;
void chmax(int &a, int b)
{
    if (a < b)
    {
        a = b;
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> colorcnt(M), personcnt(M);
    for (int i = 0; i < k * n; i++)
    {
        int x;
    	cin>>x;
        colorcnt[x]++;
    }
    for(int i=0;i<n;i++)
    {
    	int x;
    	cin>>x;
    	personcnt[x]++;
    }
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n * k + 1));
    for (int i = 1; i <= n; i++)
    {
    	for(int j=n*k;j>0;j--)
    	{
    		for(int x=0;x<=min(j,k);x++)
    		{
    			chmax(dp[i][j],dp[i-1][j-x]+h[x]);
    		}
    	}
    }
    int ans=0;
    for(int i=0;i<M;i++)
    {
    	ans+=dp[personcnt[i]][colorcnt[i]];
    }
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
