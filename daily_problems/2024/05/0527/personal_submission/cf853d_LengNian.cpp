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



int f(int x, int y, int n)
{
    return x * n + y;
}
signed main()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<int> dp(n * n, 0);

    for (int i = 0; i < n; i ++ )
    {
        dp[f(i, i, n)] = 1;
    }

    for (int k = 2; k <= n; k ++ )
    {
        for (int i = 0; i <= n - k; i ++ )
        {
            int j = i + k - 1;
            if (s[i] == s[j] && (k == 2 || dp[f(i + 1, j - 1, n)]))
            {
                dp[f(i, j, n)] = dp[f(i, i + k / 2  -1, n)] + 1;
            }
        }
    }

    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            cnt[dp[f(i, j, n)]] += 1;
        }
    }

   
    for (int i = n; i > 0; i -- )
    {
        cnt[i -1] += cnt[i];
    }
    for (int i = 1; i <= n; i ++ )
    {
        if (i != 1) cout << " ";
        cout << cnt[i];
    }

    cout <<  "\n";

    return 0;
}
