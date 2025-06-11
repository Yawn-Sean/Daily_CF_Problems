#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
const int inf = 1E9 + 1;
void solve()
{
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<vector<int>> a(n + 1, vector<int>(m + 1,inf));
    for(int i=1;i<=q;i++)
    {
    	int x,y,t;
    	cin>>x>>y>>t;
    	a[x][y]=t;
    }
    int l = 0, r = inf;
    while (l < r)
    {
        int mid = (l + r) / 2;
        vector<vector<int>> pre(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (a[i][j] <= mid);
            }
        }
        int f = 0;
        auto get=[&](int x1,int y1,int x2,int y2)
        {
        	
        	return pre[x1][y1]-pre[x2-1][y1]-pre[x1][y2-1]+pre[x2-1][y2-1];
        };
        for (int i = 1; i <= n - k + 1; i++)
        {
            for (int j = 1; j <= m - k + 1; j++)
            {
                if (get(i+k-1,j+k-1,i,j)== k * k)
                {
                    f = 1;
                    break;
                }
            }
        }
        if (f)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    int ans = l == inf ? -1 : l;
    cout << ans;
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
