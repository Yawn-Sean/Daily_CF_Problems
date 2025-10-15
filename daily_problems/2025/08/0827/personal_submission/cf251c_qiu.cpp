#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define ull unsigned long long
using namespace std;
typedef pair<int, int> PII;
const int N = 2000005, mod = 998244353;
vector<int> e[N];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
void solve()
{
    int a, b, k;
    cin >> a >> b >> k;
    int num = 1;
    for (int i = 2; i <= k; i++)
    {
        num = lcm(i, num);
    }

    int ans = 0;
    if (a / num != b / num)
    {
        vector<int> dp(num + 1, 1e17);
        dp[0] = 0;
        for (int i = 1; i <= num; i++)
        {
            dp[i] = min(dp[i], dp[i - 1] + 1);
            for (int j = 2; j <= k; j++)
                dp[i] = min(dp[i], dp[i - i % j] + 1);
        }
        ans = dp[a % num];
        a = a / num * num;
        ans += (a - b) / num * dp[num];

        a -= (a - b) / num * num;
    }
    // cout << num << ' ' << a << ' ' << b << endl;
    vector<int> dp(num + 1, 1e17);
    dp[0] = 0;
    for (int i = 1; i <= num; i++)
    {
        dp[i] = min(dp[i], dp[i - 1] + 1);
        for (int j = 2; j <= k; j++)
            if (i - (b + i) % j >= 0)
                dp[i] = min(dp[i], dp[i - (b + i) % j] + 1);
    }
    ans += dp[a - b];
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;

    // cin >> T;
    while (T--)
        solve();
    // cout << idx << endl;
    return 0;
}
