#include <bits/stdc++.h>

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
#define int long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i = 1; i < n; i++)
    {
        if (n % i)
            continue;
        bool flg = true;
        for (int u = 0; u < n; u++)
        {
            sort(all(adj[u]));
            for (int v : adj[u])
            {
                if (!binary_search(all(adj[(u + i) % n]), (v + i) % n))
                {
                    flg = false;
                    break;
                }
            }
        }
        if (flg)
            return cout << "Yes\n", 0;
    }
    cout << "No";
}
