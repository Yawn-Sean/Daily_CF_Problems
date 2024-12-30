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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;
    int len = s.size();

    vector<int> q(m);
    for (int i = 0; i < m; i++)
    {
        cin >> q[i], q[i]--;
    }
    vector<int> z(len);

    int j = 0;
    for (int i = 1; i < len; i++)
    {
        z[i] = (j + z[j] <= i ? 0 : min(j + z[j] - i, z[i - j]));
        while ((i + z[i] < len) && (s[z[i]] == s[i + z[i]]))
            z[i]++;
        if (j + z[j] < i + z[i])
            j = i;
    }
    for (int i = 1; i < m; i++)
    {
        int idx = q[i] - q[i - 1];
        if (idx >= len)
            continue;
        if (z[idx] + idx != len)
        {
            cout << "0\n";
            return 0;
        }
    }

    vector<int> dif(n + 1);
    for (auto &p : q)
    {
        dif[p]++, dif[p + len]--;
    }

    i64 ans = 1;
    int mod = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
        dif[i + 1] += dif[i];
        if (!dif[i])
            ans = ans * 26 % mod;
    }

    cout << ans << '\n';

    return 0;
}
