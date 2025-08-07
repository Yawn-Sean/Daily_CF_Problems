#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = -1e18;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int tr[N * 4], ls[N * 4], rs[N * 4], tot, cnt[N * 4], sum[N * 4];
int root;
void pushup(int u)
{
    sum[u] = sum[ls[u]] + sum[rs[u]];
    cnt[u] = cnt[ls[u]] + cnt[rs[u]];
}
void insert(int &u, int l, int r, int pos, int val)
{
    if (!u)
        u = ++tot;
    if (l == r)
    {
        cnt[u] += val;
        sum[u] += val * pos;
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid)
        insert(ls[u], l, mid, pos, val);
    else
        insert(rs[u], mid + 1, r, pos, val);
    pushup(u);
}
int query(int u, int l, int r, int k)
{
    if (!u)
        return 0;
    if (cnt[u] <= k)
    {
        return sum[u];
    }
    if (l == r)
    {
        return k * l;
    }
    int ans = 0;
    int mid = l + r >> 1;
    if (ls[u] && k <= cnt[ls[u]])
        ans += query(ls[u], l, mid, k);
    else
    {
        ans += sum[ls[u]];
        if (rs[u])
            ans += query(rs[u], mid + 1, r, k - cnt[ls[u]]);
    }
    return ans;
}
void solve()
{
    int n, k, m;
    cin >> n >> k >> m;
    vector<PII> a[n + 10];
    int maxval = 0;
    for (int i = 0; i < m; i++)
    {
        int l, r, c, p;
        cin >> l >> r >> c >> p;
        a[l].push_back({c, p});
        a[r + 1].push_back({-c, p});
        maxval = max(maxval, p);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto [x, y] : a[i])
        {
            insert(root, 1, maxval, y, x);
        }
        ans += query(root, 1, maxval, k);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}