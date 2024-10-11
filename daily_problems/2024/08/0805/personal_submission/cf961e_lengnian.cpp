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

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = min(a[i], (long long)200001);
        v[a[i]].pb(i);
    }

    int ans = 0;
    for (int i = 200001; i >= 0; i--)
    {
        for (auto t : v[i])
        {
            add(t, 1);
        }
        if (a[i] > i)
            ans += query(a[i]) - query(i);
    }

    cout << ans << "\n";
    return 0;
}
