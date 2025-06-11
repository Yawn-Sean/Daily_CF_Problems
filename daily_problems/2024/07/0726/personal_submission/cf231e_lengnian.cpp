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
// #define int long long
const int MOD = 1000000007;
const int N = 110000;

vector<int> edge[N];
pii st[N];
int f[N][18];
int sum[N], dep[N], col[N], color;
/*
如果使用define int long long
自己定义的pow会使用库函数中的pow，最终输出浮点数
所以换一下函数名可以解决
*/

int lca(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    for (int k = dep[x] - dep[y], i = 0; i <= 16; i++)
        if ((k >> i) & 1)
            x = f[x][i];
    if (x == y)
        return x;
    for (int i = 16; i >= 0; i--)
        if (f[x][i] != f[y][i])
            x = f[x][i],
            y = f[y][i];
    return f[x][0];
}

int getsum(int x, int y)
{
    int ans = sum[x] - sum[f[y][0]];
    if (col[f[y][0]] == col[y] && col[y])
        ans++;
    return ans;
}

int Pow(int a, int n)
{
    int ret = 1;
    while (n)
        if (n & 1)
            n--, ret = (long long)ret * a % MOD;
        else
            n >>= 1, a = (long long)a * a % MOD;
    return ret;
}

void init()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }

    memset(dep, 0xff, sizeof(dep));
    int tot = 1;
    st[tot] = make_pair(1, 0);
    dep[1] = 1;
    for (; tot;)
    {
        int x = st[tot].fi, &e = st[tot].se;
        if (e == edge[x].size())
        {
            tot--;
            continue;
        }
        int y = edge[x][e++];
        if (dep[y] == -1)
        {
            dep[y] = dep[x] + 1;
            f[y][0] = x;
            st[++tot] = make_pair(y, 0);
            continue;
        }
        if (y != f[x][0] && dep[x] > dep[y])
        {
            color++;
            for (int i = tot; i; i--)
            {
                col[st[i].fi] = color;
                if (st[i].fi == y)
                    break;
            }
        }
    }

    st[tot = 1] = make_pair(1, 0);
    sum[1] = col[1] != 0;
    for (; tot;)
    {
        int x = st[tot].fi, &e = st[tot].se;
        if (e == edge[x].size())
        {
            tot--;
            continue;
        }
        int y = edge[x][e++];
        if (f[y][0] == x)
        {
            sum[y] = sum[x];
            if (col[y] && col[y] != col[x])
                sum[y]++;
            st[++tot] = make_pair(y, 0);
            continue;
        }
    }

    for (int k = 1; k <= 16; k++)
        for (int x = 1; x <= n; x++)
            f[x][k] = f[f[x][k - 1]][k - 1];
}
signed main()
{
    init();
    int T;
    cin >> T;
    while (T--)
    {
        int x, y;
        cin >> x >> y;
        int f = lca(x, y);
        int ans = getsum(x, f) + getsum(y, f);
        if (col[f])
            ans--;
        cout << Pow(2, ans) << endl;
    }

    return 0;
}
