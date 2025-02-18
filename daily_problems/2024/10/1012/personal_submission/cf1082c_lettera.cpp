#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
void solve()
{
    // 对每个物品求出前缀和
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m + 1);
    vector<int> ans(n + 1);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    for (int i = 1; i <= m; i++)
    {
        sort(a[i].rbegin(), a[i].rend());
        int cur = 0;
        for (int j = 0; j < a[i].size(); j++)
        {
            cur += a[i][j];\
            if(cur<0)
            {
            	break;
            }
            ans[j + 1] +=cur;
        }
    }
    cout << *max_element(ans.begin(), ans.end());
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
