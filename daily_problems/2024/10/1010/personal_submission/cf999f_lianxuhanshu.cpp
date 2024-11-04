#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e5 + 10, mod = 1e9 + 7;
int n, m, k;

int color[N], people[N];
int f[N];
int dp[505][5005];
int h[15];
void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n * k; i++)
    {
        int c;
        cin >> c;
        color[c]++;
    }

    for (int i = 0; i < n; i++)
    {
        int f;
        cin >> f;
        people[f]++;
    }

    for (int i = 1; i <= k; i++)
        cin >> h[i];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n * k; j++)
            for (int u = 0; u <= k; u++)
            {
                if (j >= u)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - u] + h[u]);
            }

    int ans = 0;
    for (int i = 1; i < N; i++)
        ans += dp[people[i]][color[i]];
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }

    return 0;
}
