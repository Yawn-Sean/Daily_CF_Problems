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

    int n;
    cin >> n;

    int cnt = 0;

    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        cnt += count(s[i].begin(), s[i].end(), '1');
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            ans += (s[j][(i + j) % n] == '1');
        }
        res = max(res, ans);
    }

    res = n - res + cnt - res;
    cout << res << "\n";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
