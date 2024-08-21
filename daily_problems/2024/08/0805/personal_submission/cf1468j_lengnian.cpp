#include <bits/stdc++.h>
// 并查集
using namespace std;

using i64 = long long;
using i128 = __int128;
using ull = unsigned long long;
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define pqi priority_queue<int> // 优先队列

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<Edge> a(m), b;
    int x = INF;
    for (int i = 0; i < m; i++)
    {
        int u, v, l;
        cin >> u >> v >> l;
        --u;
        --v;
        a[i] = {u, v, max(0, l - k)};
        if (l <= k)
        {
            b.pb({u, v, k - l});
        }
        else
        {
            x = min(x, l - k);
        }
    }

    sort(all(a));
    sort(all(b));
    i64 ans = 0;
    DSU t(n);
    for (auto [u, v, l] : a)
    {
        if (t.merge(u, v))
        {
            ans += l;
        }
    }

    if (ans == 0)
    {
        ans = x;
    }

    int cnt = 0;
    t = n;
    for (auto [u, v, l] : b)
    {
        if (t.merge(u, v))
        {
            cnt++;
        }
    }
    if (cnt == n - 1)
    {
        ans = min(ans, (long long)b[0].l);
    }

    cout << ans << "\n";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
