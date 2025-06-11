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

const int INF = 1e9 + 7;
const int N = 1010;
int a[10], ans[10];
int d[N][N];
char c[N][N];
bool used[1001][1001];
vector<pii> v[10];
pii dt[] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void solve()
{
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= p; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> c[i][j];
            d[i][j] = INF;
            if (c[i][j] >= '1' && c[i][j] <= '9')
            {
                used[i][j] = 1;
                v[c[i][j] - 48].pb({i, j});
            }
        }
    }
    for (int t = 1; t <= 1e6; t++)
    {
        for (int x = 1; x <= p; x++)
        {
            ans[x] += (v[x]).size();
            queue<pii> q;
            for (auto [i, j] : v[x])
            {
                q.push({i, j});
                used[i][j] = 1;
                d[i][j] = 0;
            }
            vector<pair<int, int>> add;
            while (!q.empty())
            {
                int i = q.front().fi;
                int j = q.front().se;
                q.pop();

                if (d[i][j] == a[x])
                    continue;
                for (auto e : dt)
                {
                    int tox = i + e.fi, toy = j + e.se;
                    if (tox < 1 || tox > n || toy < 1 || toy > m)
                        continue;
                    if (c[tox][toy] == '#' || used[tox][toy])
                        continue;

                    d[tox][toy] = d[i][j] + 1;
                    used[tox][toy] = 1;
                    add.pb({tox, toy});
                    q.push({tox, toy});
                }
            }
            swap(v[x], add);
            add.clear();
        }
    }
    for (int i = 1; i <= p; ++i)
        cout << ans[i] << ' ';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
