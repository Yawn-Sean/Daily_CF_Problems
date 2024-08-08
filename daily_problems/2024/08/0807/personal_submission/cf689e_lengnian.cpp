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

const int N = 2e5 + 5;

const int mod = 1e9 + 7;

void add(int &a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}

int sum(int a, int b)
{
    add(a, b);
    return a;
}

int mult(int a, int b)
{
    return (1ll * a * b) % mod;
}

int n, k, f[N], inv[N], ans;

map<int, int> x;

int bp(int a, int n)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
            ans = mult(ans, a);
        a = mult(a, a);
        n >>= 1;
    }
    return ans;
}

int cnk(int n, int k)
{
    if (k > n)
        return 0;
    int ans = mult(f[n], inv[k]);
    ans = mult(ans, inv[n - k]);
    return ans;
}

clock_t start = clock();

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    f[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        f[i] = mult(f[i - 1], i);
        inv[i] = bp(f[i], mod - 2);
    }

    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        x[l]++, x[r + 1]--;
    }

    vector<pair<int, int>> all;
    for (auto i : x)
        all.pb(mp(i.fi, i.se));

    for (int i = 0, cur = 0; i + 1 < all.size(); i++)
    {
        int len = all[i + 1].fi - all[i].fi;
        cur += all[i].se;
        add(ans, mult(len, cnk(cur, k)));
    }
    cout << ans << endl;

    return 0;
}
