#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef pair<int, int> PII;
const int N = 300005, mod = 998244353;

int rev4 = ((mod + 1) / 2 + mod) / 2;
void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    int x, y;
    x = 0, y = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0')
            x++;
        else
            y++;
    }
    vector<int> p(n + 1, 0);
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * 2 % mod;
    }
    auto pw = [&](int x) -> int
    {
        if (x == -1)
            return (mod + 1) / 2;
        if (x == -2)
            return rev4;
        return p[x];
    };
    auto cal = [&](int x, int y) -> int
    {
        return (x * (x + 1) % mod * pw(n - 2) % mod + y * (y + 1) % mod * pw(n - 2) % mod - x * y % mod * pw(n - 1) % mod - pw(n - 1) + 2 * mod) % mod * rev4 % mod;
    };

    while (q--)
    {
        int pos;
        cin >> pos;
        if (s[pos] == '0')
        {
            s[pos] = '1';
            x--;
            y++;
        }
        else
        {
            s[pos] = '0';
            x++;
            y--;
        }
        cout << cal(x, y) << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;

    cin >> T;
    while (T--)
        solve();
    return 0;
}
