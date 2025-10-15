#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int N = 5010, mod = 1e9 + 7;
vector<int> e[N];
int dep[N];
int n, m, w;
struct node
{
    int k, p, c;
};
vector<node> info[N];

vector<node> ans;
int vis[N];
void bfs(int u, int fa, int len)
{
    queue<PII> q;
    q.push({u, 0});

    while (!q.empty())
    {
        auto [u, val] = q.front();
        q.pop();
        if (val > len || vis[u])
            continue;
        vis[u] = true;
        dep[u] = val;
        for (auto v : e[u])
        {
            if (vis[v] || val == len)
                continue;
            q.push({v, val + 1});
        }
    }
}
bool check(int a, LL g, int r, int len)
{
    for (int i = 1; i <= n; i++)
    {
        vis[i] = false;
        dep[i] = n + 1;
    }
    bfs(a, 0, len);
    int l = 0, lr = w;
    while (r > 0 && l < lr)
    {
        auto [k, p, c] = ans[l];
        if (dep[c] > len)
        {
            l++;
            continue;
        }
        int need = min(r, k);
        if ((long long)need * p > (long long)g)
            return false;
        else
        {
            r -= need;
            g -= (LL)need * p;
            if (r == 0)
                return true;
            l++;
        }
    }
    return false;
}
void solve()
{

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    cin >> w;
    for (int i = 1; i <= w; i++)
    {
        int c, k, p;
        cin >> c >> k >> p;
        info[c].push_back({k, p, c});
        ans.push_back({k, p, c});
    }
    sort(ans.begin(), ans.end(), [&](const node &a, const node &b)
         { return a.p < b.p; });
    int q;
    cin >> q;
    while (q--)
    {
        int g, r;
        LL a;
        cin >> g >> r >> a;
        int l = 0, rr = n + 1;
        while (l < rr)
        {
            int mid = l + rr >> 1;
            if (check(g, a, r, mid))
                rr = mid;
            else
                l = mid + 1;
        }
        if (l == n + 1)
        {
            cout << -1 << "\n";
        }
        else
            cout << l << "\n";
    }
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
