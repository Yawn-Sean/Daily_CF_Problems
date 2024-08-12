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

const int N = 1005;
int f[N];
int n, k;

int calc(int n, int m)
{
    m = min(m, n - m);
    int ans = 1;
    for (int i = n; i >= n - m + 1; i--)
        ans = ans * i;
    for (int i = 1; i <= m; i++)
        ans = ans / i;
    return ans;
}

int js(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans = ans * i;
    return ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    f[n] = 1;

    for (int i = n - 1; i >= n - k; i--)
    {

        f[i] = calc(n, i) * js(n - i);
        for (int j = i + 1; j <= n; j++)
        {
            f[i] = f[i] - f[j] * calc(j, i);
        }
    }

    int ans = 0;
    for (int i = n - k; i <= n; i++)
    {
        ans += f[i];
    }

    cout << ans << "\n";
    return 0;
}
