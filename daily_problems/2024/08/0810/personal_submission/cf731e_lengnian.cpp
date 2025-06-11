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

const int N = 1e6 + 10;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[N]{};
    int s[N]{};
    int f[N]{};
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    f[n] = 0;
    int x = n;
    for (int i = n - 1; i; i--)
    {
        f[i] = s[x] - f[x];
        if (s[i] - f[i] > s[x] - f[x])
            x = i;
    }

    cout << f[1];
    return 0;
}
