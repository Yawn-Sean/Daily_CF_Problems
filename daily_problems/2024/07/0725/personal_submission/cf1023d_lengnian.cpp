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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), l(m, n), r(m, -1);
    l[0] = 0, r[0] = n - 1;

    int p = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;

        if (~a[i])
        {
            l[a[i]] = min(l[a[i]], i);
            r[a[i]] = max(r[a[i]], i);
        }
        else
        {
            p = i;
        }
    }

    for (int i = m - 1; ~i; i--)
    {
        if (l[i] > r[i])
        {
            if (~p)
            {
                l[i] = r[i] = p;
            }
            else
            {
                cout << "NO" << "\n";
            }
        }
        else
        {
            p = l[i];
        }
    }
    vector<int> b(n), f(n + 1);
    for (int i = 0; i <= n; i++)
    {
        f[i] = i;
    }
    auto find = [&](int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    };
    for (int i = m - 1; ~i; i--)
    {
        for (int x = find(l[i]); x <= r[i]; x = find(x))
        {
            b[x] = i;
            f[find(x)] = find(x + 1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (~a[i] && a[i] != b[i])
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        cout << b[i] + 1 << " ";
    }

    cout << "\n";
    return 0;
}
