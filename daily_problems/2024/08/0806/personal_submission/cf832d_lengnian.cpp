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
const int N = 100005;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        int u;
        cin >> u;
        g[u].push_back(i);
        g[i].push_back(u);
    }
    dfs(1, 0);
    lca_init();
    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << max(query(a, b, c), max(query(b, a, c), query(c, a, b))) << endl;
    }
    return 0;
}
