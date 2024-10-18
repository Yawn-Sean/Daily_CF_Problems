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

int l, r, x, y;

bool solve(i64 a)
{
    i64 b = y / a * x;
    return l <= a && a <= r && l <= b && b <= r && __gcd(a, b) == x;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> l >> r >> x >> y;

    int res = 0;
    for (int i = 1; i * i <= y; i++)
    {
        if (y % i == 0)
        {
            res += solve(i);
            if (i * i < y)
            {
                res += solve(y / i);
            }
        }
    }

    cout << res << "\n";
    return 0;
}
