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

const int inf = 1e9;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    if (s.size() != t.size())
    {
        cout << -1 << "\n";
        return 0;
    }

    int n = s.size();
    int m;
    cin >> m;

    vector dp(26, vector(26, inf));

    for (int i = 0; i < 26; i++)
    {
        dp[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        char a, b;
        int c;
        std::cin >> a >> b >> c;
        int x = a - 'a', y = b - 'a';
        dp[x][y] = std::min(dp[x][y], c);
    }

    for (int k = 0; k < 26; k++)
    {
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int ans = 0;
    string c;
    for (int i = 0; i < n; i++)
    {
        int res = 1e9;
        int x = s[i] - 'a', y = t[i] - 'a';
        int z = 0;
        for (int j = 0; j < 26; j++)
        {
            if (dp[x][j] + dp[y][j] < res)
            {
                res = dp[x][j] + dp[y][j];
                z = j;
            }
        }

        c += 'a' + z;
        ans = min(inf, ans + res);
    }
    if (ans == 1e9)
    {
        cout << -1 << "\n";
        return 0;
    }
    cout << ans << "\n";
    cout << c << "\n";

    return 0;
}
