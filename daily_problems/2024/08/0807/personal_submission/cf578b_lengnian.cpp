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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] | a[i];
    }
    vector<int> g(n + 2);
    for (int i = n; i >= 1; i--)
    {
        g[i] = g[i + 1] | a[i];
    }
    int res = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        res = a[i];
        for (int j = 1; j <= k; j++)
            res *= x;
        ans = max(ans, res | f[i - 1] | g[i + 1]);
    }

    cout << ans;

    return 0;
}
