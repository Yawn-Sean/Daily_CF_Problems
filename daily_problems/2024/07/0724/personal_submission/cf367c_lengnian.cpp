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

int f(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else if (n % 2 == 1)
    {
        return n * (n - 1) / 2 + 1;
    }
    else
    {
        return n * (n - 1) / 2 + 1 + (n - 2) / 2;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        cin >> b[i];
    }

    int ans = 0;
    while (f(ans + 1) <= n && ans < m)
    {
        ans++;
    }

    sort(all(b), greater<int>());

    int res = 0;
    for (int i = 0; i < ans; i++)
    {
        res += b[i];
    }

    cout << res << "\n";

    return 0;
}
