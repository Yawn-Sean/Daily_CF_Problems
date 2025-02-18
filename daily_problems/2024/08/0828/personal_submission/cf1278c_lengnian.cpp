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

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(2 * n + 1);
        for (int i = 1; i <= 2 * n; i++)
        {
            cin >> a[i];
        }

        int l1 = 0, r1 = 0, l2 = 0, r2 = 0;
        for (int i = n; i >= 1; i--)
        {
            if (a[i] == 1)
                l1++;
            l2 = n - l1;
        }

        for (int i = n + 1; i <= 2 * n; i++)
        {
            if (a[i] == 1)
                r1++;
            r2 = n - r1;
        }
        map<int, int> mp;
        int x = r1, y = r2;
        mp[r1 - r2] = 0;
        for (int i = n + 1; i <= 2 * n; i++)
        {
            if (a[i] == 1)
                x--;
            else
                y--;
            if (!mp.count(x - y))
                mp[x - y] = i - n;
        }

        int t1, t2, ans = 2 * n;
        for (int l = 0; l <= n; l++)
        {

            if (mp.count(-1 * (l1 - l2)))
                ans = min(ans, l + mp[-1 * (l1 - l2)]);

            if (a[n - l] == 1)
                l1--;
            else
                l2--;
        }
        cout << ans << "\n";
    }
    return 0;
}
