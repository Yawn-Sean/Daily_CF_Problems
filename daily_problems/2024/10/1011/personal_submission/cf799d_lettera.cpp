#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
void solve()
{
    int a, b, h, w, n;
    cin >> a >> b >> h >> w >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    sort(num.rbegin(), num.rend());
    n = min(n, 34);
    int inf = 100;
    auto get = [&](int x, int y) -> int {
        map<pair<int, int>, int> mp;
        mp[{x, y}] = 0;
        for (int i = 0; i < n; i++)
        {
            vector<pair<int, int>> tmp;
            for (auto [x, y] : mp)
            {
                tmp.push_back(x);
            }
            for(auto [x,y]:tmp)
            {
            	int nx=(x+num[i]-1)/num[i];
            	int ny=(y+num[i]-1)/num[i];
            	if(!mp.count({nx,y}))
            	{
            		mp[{nx,y}]=mp[{x,y}]+1;
            	}
            	if(!mp.count({x,ny}))
            	{
            		mp[{x,ny}]=mp[{x,y}]+1;
            	}   
            }
        }
        if (mp.count({1, 1}))
        {
            return mp[{1, 1}];
        }
        else
        {
            return inf;
        }
    };
    int ans = min(get((a + w - 1) / w, (b + h- 1) / h), get((a + h - 1) / h, (b + w- 1) / w));
    cout << (ans == inf ? -1 : ans);
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
