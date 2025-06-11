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
const int inf = 1e9 + 7;

int dp[110][60];
int v[60];

int mod;
int M(int x)
{
    return x >= mod ? x - mod : x;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k >> mod;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = (a[i - 1] + a[i]) % mod;
    }

    for (int i = 0; i < mod; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = -inf;
        }
    }

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            v[j] = -inf;
            for (int m = 0; m < mod; m++)
            {
                v[j] = max(v[j], M(m + a[i]) + dp[m][j - 1]);
            }
        }

        for (int j = 1; j <= k; j++)
        {
            dp[M(mod - a[i])][j] = max(dp[M(mod - a[i])][j], v[j]);
        }
        if (i == n)
        {
            cout << v[k];
        }
    }

    return 0;
}
