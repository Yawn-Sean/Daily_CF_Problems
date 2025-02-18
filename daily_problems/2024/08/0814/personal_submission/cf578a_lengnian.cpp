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
    int a, b;
    cin >> a >> b;
    if (a < b)
    {
        cout << -1 << "\n";
        return 0;
    }
    long double res = 1e18;
    for (int i = -1; i <= 1; i += 2)
    {
        int c = a + i * b;
        if (c < 2 * b)
        {
            continue;
        }
        int x = c / (2 * b);
        res = min(res, (long double)c / (2. * x));
    }

    if (res > 1e17)
    {
        cout << "-1" << "\n";
    }
    else
    {
        cout << fixed << setprecision(18) << static_cast<double>(res) << "\n";
    }

    return 0;
}
