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

const int N = 3010;
vector<int> a[N], b[N];
int s[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[v].pb(u);
        b[u].pb(v);
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++)

    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;

            for (auto x : a[i])
                s[x] = 1;
            int cnt = 0;
            for (auto x : b[j])
                cnt += s[x];
            for (auto x : a[i])
                s[x] = 0;
            ans = ans + (cnt * (cnt - 1) / 2);
        }
    }

    cout << ans;
    return 0;
}
