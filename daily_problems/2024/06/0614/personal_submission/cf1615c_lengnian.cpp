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
    string s1, s2;
    cin >> n >> s1 >> s2;

    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        c1 += (s1[i] == '1'), c2 += (s2[i] == '1');
    }

    int ans = n + 5;

    if (c1 == c2)
    {
        int res = 0;
        for (int i = 0; i < n; i++)
            res += (s1[i] != s2[i]);
        ans = min(ans, res);
    }
    if (n - c1 + 1 == c2)
    {
        int res = 0, f = 0;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == s2[i])
            {
                res += 1, f |= (s1[i] == '1');
            }
        }

        ans = min(ans, res + 2 - f * 2);
    }

    cout << (ans < n + 5 ? ans : -1) << '\n';
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
