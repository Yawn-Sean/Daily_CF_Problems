#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
#define pll pair<i64, i64>
#define pii pair<int, int>
#define vi vector<int>
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define pqi priority_queue<int>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int N = 100000 + 10, MOD = 1000000007;

i64 ne[N];
bool flag[N];
string s, t;

int main()
{
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    ne[1] = 0;
    for (int i = 2; i <= m; i++)
    {
        i64 k = ne[i - 1];
        while (k && t[k] != t[i - 1])
            k = ne[k];
        if (t[k] == t[i - 1])
            k++;
        ne[i] = k;
    }
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j && t[j] != s[i - 1])
            j = ne[j];
        if (t[j] == s[i - 1])
            j++;
        if (j == m)
            flag[i] = true, j = ne[j];
    }

    i64 f[N]{}, g[N]{}, sum[N]{}, pre[N]{};
    pre[0] = -1;
    for (int i = 1; i <= n; ++i)
        if (flag[i])
            pre[i] = i - m;
        else
            pre[i] = pre[i - 1];

    f[0] = sum[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (pre[i] >= 0)
            f[i] = ((pre[i] + 1LL) * sum[pre[i]] - g[pre[i]]) % MOD;
        sum[i] = (sum[i - 1] + f[i]) % MOD;
        g[i] = (g[i - 1] + f[i] * i) % MOD;
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++)
        (ans += f[i]) %= MOD;
    ans = (ans + MOD) % MOD;
    cout << ans << "\n";
    return 0;
}
