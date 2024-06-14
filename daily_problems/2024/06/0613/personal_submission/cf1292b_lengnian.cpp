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
// #define int long long

const int inf = 5e16;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    i64 x1, y1, bx, by, t, x2, y2;
    int ax, ay;
    cin >> x1 >> y1 >> ax >> ay >> bx >> by >> x2 >> y2 >> t;

    vector<pair<i64, i64>> p;
    while (x1 <= 5E16 && y1 <= 5E16)
    {
        p.emplace_back(x1, y1);
        x1 = ax * x1 + bx;
        y1 = ay * y1 + by;
    }

    int ans = 0;
    for (int i = 0; i < int(p.size()); i++)
    {
        for (int j = 0; j < int(p.size()); j++)
        {
            if (abs(x2 - p[i].first) + abs(y2 - p[i].second) + abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second) <= t)
            {
                ans = max(ans, abs(i - j) + 1);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
