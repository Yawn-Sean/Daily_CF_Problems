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

void solve()
{
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(all(a));
    vector<int> sum(n + 1);
    for (int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i] + a[i];
    }

    for (int i = 2 * k - 1; i < n; i++)
    {
        a[i] += a[i - k];
    }

    for (int i = 0; i < k - 1; i++)
    {
        a[i] = 0;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum[(i + 1) % k] + a[i] <= p)
        {
            ans = i + 1;
        }
    }

    cout << ans << "\n";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
