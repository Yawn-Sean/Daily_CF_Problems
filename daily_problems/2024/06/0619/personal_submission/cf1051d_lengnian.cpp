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

const int N = 1010;
const int mod = 998244353;
int dp[N][N << 1][4];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    dp[0][1][0] = dp[0][2][1] = dp[0][2][2] = dp[0][1][3] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < N << 1; j++)
            for (int k = 0; k < 4; k++)
            {
                if (!dp[i - 1][j][k])
                    continue;
                for (int u = 0; u < 4; u++)
                {
                    int add = __builtin_popcount(k ^ u);
                    if ((u == 0 || u == 3) && add)
                    {
                        add--;
                    }

                    dp[i][j + add][u] += dp[i - 1][j][k];
                    dp[i][j + add][u] -= dp[i][j + add][u] >= mod ? mod : 0;
                }
            }
    }

    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        ans += dp[n - 1][k][i];
        ans -= ans >= mod ? mod : 0;
    }
    cout << ans << "\n";
    return 0;
}
