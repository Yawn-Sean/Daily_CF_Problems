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

struct DSU
{
    int x, y, l, r;
    bool operator<(const DSU &a) const
    {
        return l < a.l;
    }
} c[3010];
int u[1010];
void init()
{
    for (int i = 0; i < 1010; i++)
        u[i] = i;
}
int find(int x)
{
    if (u[x] == x)
        return x;
    return u[x] = find(u[x]);
}
void merge(int x, int y)
{
    x = find(x), y = find(y);
    u[x] = y;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int res = -1;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> c[i].x >> c[i].y >> c[i].l >> c[i].r;
    }

    sort(c, c + m);
    for (int i = 0; i < m; i++)
    {
        init();
        for (int j = 0; j < m; j++)
        {
            if (c[j].l > c[i].r)
                break;
            if (c[j].r < c[i].r)
                continue;
            merge(c[j].x, c[j].y);
            if (find(1) == find(n))
            {
                res = max(res, c[i].r - c[j].l + 1);
                break;
            }
        }
    }

    if (res < 0)
        cout << "Nice work, Dima!\n";
    else
        cout << res << "\n";
    return 0;
}
