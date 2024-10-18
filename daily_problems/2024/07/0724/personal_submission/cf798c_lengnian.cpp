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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int g = gcd(a[0], a[1]);
    for (int i = 2; i < n; i++)
    {
        g = gcd(g, a[i]);
    }

    int res = 0;
    if (g == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
            {
                continue;
            }
            else
            {
                if (i == n - 1)
                {
                    res += 2;
                }
                else if (a[i + 1] % 2 == 1)
                {
                    res += 1;
                    a[i + 1] = 2;
                }
                else
                {
                    res += 2;
                }
            }
        }
    }

    cout << "YES\n";
    cout << res << "\n";
    return 0;
}
