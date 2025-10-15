#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
void chmax(int &a, int b)
{
    a = max(a, b);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    vector<array<int, 4>> dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
   int dp0=a[1],dp1=b[1];
    for(int i=2;i<=n;i++)
    {
    	int t=max(dp0+b[i],dp1+a[i]);
    	dp1=max(dp0+c[i],dp1+b[i]);
    	dp0=t;
    }
	cout<<dp0;
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
}
