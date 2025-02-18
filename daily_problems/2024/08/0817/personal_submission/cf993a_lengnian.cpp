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
// #define mp make_pair
#define fi first
#define se second
#define int long long

const int mod = 1e9 + 7;
const int N = 500500;

i64 p2(i64 a)
{
    if (a == 0)
        return 1;
    i64 r = p2(a / 2);
    r = (r * r) % mod;
    if (a & 1)
        r = (r * 2) % mod;
    return r;
}

map<i64, int> mp;

vector<pii> E[N];

i64 val[N];

int pai[N];
int last[N];
int uf = 1;
inline int find(int x)
{
    if (last[x] < uf)
    {
        last[x] = uf;
        pai[x] = x;
    }
    return pai[x] = (x == pai[x]) ? x : find(pai[x]);
}
inline void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    last[a] = last[b] = uf;
    if (a == b)
        return;
    pai[a] = b;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        cin >> val[i];

    int cur = 1;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b, a--, b--;
        i64 xx = val[a] ^ val[b];
        if (mp[xx] == 0)
            mp[xx] = cur++;
        int id = mp[xx];
        E[id].pb(pii(a, b));
    }

    int ans = 0;

    for (int i = 1; i < cur; i++)
    {
        uf++;
        int uu = n;
        for (int j = 0; j < E[i].size(); j++)
        {
            pii u = E[i][j];
            int A = u.first, B = u.second;
            A = find(A);
            B = find(B);
            if (A != B)
                uu--;
            merge(A, B);
        }
        int qtd = p2(n) - p2(uu) + mod;
        qtd %= mod;
        ans += qtd;
        ans %= mod;
    }

    int res = (p2(n) * p2(k)) % mod;
    res -= ans;
    res += mod;
    res %= mod;
    cout << res << "\n";
}
