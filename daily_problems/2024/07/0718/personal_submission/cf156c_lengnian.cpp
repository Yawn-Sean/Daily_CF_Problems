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
const int mod = 1e9 + 7, N = 110;
int dp[N][N + 26];

void init()
{
    for (int i = 1; i <= 26; i++)
        dp[1][i] = 1;
    for (int i = 2; i < N; i++)
        for (int j = i; j <= i * 26; j++)
        {
            for (int k = 1; k <= 26; k++)
                if (j - k >= 1)
                    dp[i][j] += dp[i - 1][j - k], dp[i][j] %= mod;
        }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    init();
    while (t--)
    {
        string s;
        cin >> s;
        int res = 0;
        for (int i = 0; i < s.size(); i++)
            res += s[i] - 'a' + 1;
        cout << dp[s.size()][res] - 1 << "\n";
    }
    return 0;
}
