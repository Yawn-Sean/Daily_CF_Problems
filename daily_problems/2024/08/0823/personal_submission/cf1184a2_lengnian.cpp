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
    string y;
    cin >> n >> y;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            bool ok = true;
            for (int j = 0; j < i; j++)
            {
                int ans = 0;
                for (int k = j; k < n; k += i)
                {
                    ans ^= (y[k] - '0');
                }
                ok &= (ans == 0);
            }
            a[i] = ok;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[__gcd(i, n)];
    }

    cout << ans << "\n";
    return 0;
}
