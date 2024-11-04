#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;
int n, m, k;

int c[N];
vector<int> g[N];
bool vis[N];
int q[N];
map<int, int> mp;

void bfs(int x)
{
    int hh = 0, tt = -1;
    q[++tt] = x;
    vis[x] = true;
    mp[c[x]]++;
    while (hh <= tt)
    {
        auto t = q[hh++];
        for (auto j : g[t])
        {
            if (vis[j])
                continue;
            vis[j] = true;
            mp[c[j]]++;
            q[++tt] = j;
        }
    }
}
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        g[l].push_back(r);
        g[r].push_back(l);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            mp.clear();
            bfs(i);
            int mx = 0, sum = 0;
            for (auto [u, v] : mp)
            {
                mx = max(mx, v);
                sum += v;
            }
            ans += sum - mx;
        }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }

    return 0;
}
