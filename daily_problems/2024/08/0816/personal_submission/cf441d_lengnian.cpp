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

const int N = 3005;
int n, m, k, p[N];
bool vis[N];
void dfs(int u)
{
    for (int v = u; !vis[v]; v = p[v])
        vis[v] = 1;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i], p[i]--;
    int m;
    cin >> m;
    m = n - m;
    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs(i), k++;
    memset(vis, 0, sizeof(vis));
    cout << abs(k - m) << "\n";
    if (k == m)
        return 0;

    if (k > m)
    {
        dfs(0);
        for (int i = 1; i < n && k > m; i++)
            if (!vis[i])
                cout << 1 << " " << i + 1 << " ", k--, dfs(i);
    }
    else
    {
        for (int i = 0; i < n && k < m; i++)
        {
            vector<int> pos(n, -1);
            int cur = 0;
            for (int j = p[i]; j != i; j = p[j])
                pos[j] = cur++;
            pos[i] = cur;
            cur = 0;
            for (int j = i + 1; j < n && k < m; j++)
            {
                if (pos[j] >= cur)
                {
                    cout << i + 1 << " " << j + 1 << " ";
                    k++;
                    cur = pos[j] + 1;
                    swap(p[i], p[j]);
                }
            }
        }
    }

    return 0;
}
