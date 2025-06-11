#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
const int mod = 1e9 + 7;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> c(m + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++)
        {
            int y;
            cin >> y;
            c[y].push_back(i);
        }
    }
    sort(c.begin(), c.end());
    ll ans=1,cur=1;
    for(int i=2;i<=m;i++)
    {
    	if(c[i]==c[i-1])
    	{
    		cur++;
    	}
    	else
    	{
    		cur=1;
    	}
    	ans=ans*cur%mod;
    }
    cout<<ans;
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
