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

    string s;
    cin >> s;

    vector<pii> a[26];
    int st = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == n || s[i] != s[i - 1])
        {
            a[s[i - 1] - 'a'].pb({st, i - 1});
            st = i;
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int k;
        char c;
        cin >> k >> c;
        int x = c - 'a';
        int ans = 0;
        int pos = -1;
        int obs = k;
        int cur = 0;
        if (a[x].empty())
        {
            cout << min(k, n) << "\n";
            continue;
        }
        for (int lf = 0; lf < a[x].size(); lf++)
        {
            if (lf)
            {
                cur -= a[x][lf - 1].second - a[x][lf - 1].first + 1;
                obs += a[x][lf].first - a[x][lf - 1].second - 1;
            }
            if (pos < lf)
            {
                pos = lf;
                cur = a[x][lf].second - a[x][lf].first + 1;
                obs = k;
            }
            while (pos + 1 < a[x].size() && a[x][pos + 1].first - a[x][pos].second - 1 <= obs)
            {
                obs -= a[x][pos + 1].first - a[x][pos].second - 1;
                ++pos;
                cur += a[x][pos].second - a[x][pos].first + 1;
            }
            int res = min(cur + k, n);
            ans = max(ans, res);
        }
        cout << ans << "\n";
    }
    return 0;
}
