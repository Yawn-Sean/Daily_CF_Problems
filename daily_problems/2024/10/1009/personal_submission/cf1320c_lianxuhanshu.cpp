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
int n, m, k, p;

struct Attack
{
    int a, ca;
} attack[N];
struct Defense
{
    int b, cb;
} defense[N];
struct Tree
{
    int l, r, v;
    int add;
} tr[N * 4];
struct Monster
{
    int x, y, z;
} monster[N];

void pushup(int u)
{
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}
void build(int u, int l, int r)
{
    if (l == r)
        tr[u] = {l, r, -defense[l].cb};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void pushdown(int u)
{
    if (tr[u].add)
    {
        tr[u << 1].add += tr[u].add, tr[u << 1].v += tr[u].add;
        tr[u << 1 | 1].add += tr[u].add, tr[u << 1 | 1].v += tr[u].add;
        tr[u].add = 0;
    }
}
void modify(int u, int l, int r, int v)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].v += v;
        tr[u].add += v;
    }
    else
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)
            modify(u << 1, l, r, v);
        if (r > mid)
            modify(u << 1 | 1, l, r, v);
        pushup(u);
    }
}

int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].v;
    else
    {
        pushdown(u);
        int res = 0;
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)
            res = query(u << 1, l, r);
        if (r > mid)
            res = max(res, query(u << 1 | 1, l, r));
        return res;
    }
}
void solve()
{
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
        cin >> attack[i].a >> attack[i].ca;
    for (int i = 1; i <= m; i++)
        cin >> defense[i].b >> defense[i].cb;

    sort(attack + 1, attack + 1 + n, [&](Attack A, Attack B)
         { return A.a < B.a; });

    sort(defense + 1, defense + 1 + m, [&](Defense A, Defense B)
         { return A.b < B.b; });

    build(1, 1, m);

    for (int i = 1; i <= p; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        monster[i] = {x, y, z};
    }
    sort(monster + 1, monster + 1 + p, [&](Monster A, Monster B)
         { return A.x < B.x; });

    int ans = -2e9;
    int L = 1;
    for (int i = 1; i <= n; i++)
    {
        int a = attack[i].a, ca = attack[i].ca;
        while (monster[L].x < a && L <= p)
        {
            int y = monster[L].y, z = monster[L].z;
            int l = 1, r = m;
            while (l < r)
            {
                int mid = l + r >> 1;
                if (defense[mid].b > y)
                    r = mid;
                else
                    l = mid + 1;
            }
            if (defense[r].b > y)
                modify(1, r, m, z);
            L++;
        }
        int q = query(1, 1, m);
        ans = max(ans, q - ca);
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
