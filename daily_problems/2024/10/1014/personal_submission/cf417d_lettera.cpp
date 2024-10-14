#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
const ll inf = 4E18;
void solve()
{
    int n, m, b;
    cin >> n >> m >> b;
    vector<array<int, 3>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1];
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++)
        {
            int y;
            cin >> y;
            a[i][2] |= 1<<y-1;
        }
    }
    auto cmp=[](array<int,3>x,array<int,3>y)
    {
    	return x[1]<y[1];
    };
    sort(a.begin()+1,a.end(),cmp);
    vector<int>dp(1<<m,inf);
    dp[0]=0;
    int ans=inf;
    for(int i=1;i<=n;i++)
    {
    	auto [x,y,z]=a[i];
    	for(int j=(1<<m)-1;j>=0;j--)
    	{
    		dp[j|z]=min(dp[j|z],dp[j]+x);
    	}
    	ans=min(ans,dp[(1<<m)-1]+y*b);
    }
    cout<<(ans==inf?-1:ans);
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
